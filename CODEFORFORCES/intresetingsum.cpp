#include<bits/stdc++.h>
#include<iostream>
#include<array>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        cout<<(a[n-1]+a[n-2])-(a[0]+a[1])<<endl;
    }
return 0;
}