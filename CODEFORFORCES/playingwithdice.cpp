#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int x,y,z,mid;
    if((a+b)%2==0){
        y=1;
        mid=(a+b)/2;
        x=mid-1;
        z=6-mid;
    }
    else{
        y=0;
        mid=(a+b+1)/2;
        x=mid-1;
        z=6-mid+1;
    }   
    if(a>b)
    cout<<z<<" "<<y<<" "<<x<<endl;
    else if(a==b)
    cout<<"0 1 0"<<endl;
    else
    cout<<x<<" "<<y<<" "<<z<<endl; 
    return 0;
}