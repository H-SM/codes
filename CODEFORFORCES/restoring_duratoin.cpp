#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
     while(t--)
    {
        long long int x,a;
        cin>>x;
        long long int a1[x],a2[x];
        for(int i=0;i<x;i++)
        cin>>a1[i];
        for(int i=0;i<x;i++)
        cin>>a2[i];
        long long int d=0;
        for(int i=0;i<x;i++){
            d=max(d,a1[i]);
        cout<<a2[i]-d<<" ";
        d=a2[i];
        }
        cout<<endl;
        }
    return 0;
}