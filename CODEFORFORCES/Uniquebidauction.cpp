#include<bits/stdc++.h>
#include<array>
using namespace std;
#define ll long long
 
ll unique(int n)
{
    ll fact=1;
    for(int i=2;i<=n;i++){
    	fact*=i;
	}
	return fact;
}
 
int main(){
	int x,t;
	cin>>t;
    while(t--){
        cin>>x;
        int arr[x];
        for(int i=0;i<x;i++){
            cin>>arr[i];
        }
        int size = sizeof(arr)/sizeof(int); 
        sort(arr,arr+size);
        int c=-1;
        int min=arr[0];
        int i=1;
        while(i!=x){
            if(min==arr[i]){
                while(arr[i]!=min||i!=x)
                    i=i+1;
                if(i==x){
                    c==0;
                    break;}
                else{
                i++;
                min=arr[i];}
            }
            else{
                i++;
                if(i==x)
                c==0;
            }
        if(c==0)
            cout<<min<<endl;
        else
            cout<<min<<endl;
        }
    }
    return 0;
}
