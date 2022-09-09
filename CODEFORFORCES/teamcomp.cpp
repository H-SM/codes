#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
      int t,a,b;
    cin>>t;
    while(t--){
    cin>>a>>b;
    cout<<min(a,min(b,(a+b)/4))<<endl;
    }
    return 0;
}
