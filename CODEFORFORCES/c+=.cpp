//https://codeforces.com/problemset/problem/1368/A
//to do 
#include<bits/stdc++.h>
#include<iostream>
#include<array>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int a,b,n,c;
    while(t--)
    {
        c=0;
        cin>>a>>b>>n;
        for(;max(a,b)<=n;c++){
            a>b?b+=a:a+=b;
        }
    cout<<c<<endl;
    }

return 0;
}