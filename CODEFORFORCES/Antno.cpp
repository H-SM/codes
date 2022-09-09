#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=0,y=0;
    //here x -> 256 and y -> 32
    while(a>=1&&c>=1&&d>=1){
        a--;c--;d--;
        ++x;
    }
    while(a>=1&&b>=1){
        a--;b--;
        ++y;
    }
    int sum=(256*x)+(32*y);
    cout<<sum<<endl;
    return 0;
}