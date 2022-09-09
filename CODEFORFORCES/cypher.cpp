#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int U(int n){
   --n;
    if(n==(-1))
    {
        n=9;
    }
    return n;
}
int D(int n){
    ++n;
    if(n==10)
    {
        n=0;
    }
    return n;
}

int main()
{
    int t;
    cin>>t;
     while(t--)
    {
        int x;
        cin>>x;
        int arr[x];
        for(int i=0;i<x;i++)
        cin>>arr[i];
        for(int i=0;i<x;i++){
            int u;
            char d;
            cin>>u;
            for(int j=0;j<u;j++){
                cin>>d;
                if(d=='U')
                arr[i]=U(arr[i]);
                else if(d=='D')
                arr[i]=D(arr[i]);
            }
        }
        for(int i=0;i<x;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}