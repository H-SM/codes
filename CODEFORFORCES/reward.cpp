#include<bits/stdc++.h>
#include<iostream>
#include<array>
using namespace std;

int main()
{
    int t;
    int a,b,c=0,d=0;
    for(int i=0;i<3;i++){
        cin>>a;
        c+=a;
    }//5
     for(int i=0;i<3;i++){
        cin>>b;
        d+=b;
    }//10
    cin>>t;
    a=c/5;
    if(c%5!=0)
        a++;
    b=d/10;
    if(d%10!=0)
        b++;
    if(t>=(a+b))
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}