#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
     while(t--)
    {
        int x,y=0;
        cin>>x;
        int arr[3];
        for(int i=0;i<3;i++)
        cin>>arr[i];
        while(x!=0){
            x=(arr[x-1]);
            y++;
        }
        if(y==3)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
    return 0;
}