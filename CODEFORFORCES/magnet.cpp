#include<bits/stdc++.h>
#include<iostream>
#include<array>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int n=1;
    int x,y;
    cin>>y;
    x=y;
    --t;
    while(t--)
    {
        cin>>y;
        if(x!=y){
            n++;
        }
        x=y;
    }
    cout<<n<<endl;

return 0;
}