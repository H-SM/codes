#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//20 = 9+8+3 389
int main()
{
    int t;
    cin>>t;
     while(t--)
    {
        int s;
        cin>>s;
        int y=9,ans=0;
        while(s!=0){
            if(s<y){
                ans=(ans*10)+s;
                s=0;
            }
            else{
                ans=(ans*10)+y;
                s-=y;
                --y;
            }
        }
        while (ans> 0) {
        cout<<(ans%10)<<endl;
        ans=ans/10;
        }
        cout<<endl;
    }
    return 0;
}