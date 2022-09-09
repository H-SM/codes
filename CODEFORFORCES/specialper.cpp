#include<bits/stdc++.h>
#include<iostream>
#include<array>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if(n==2)
            cout<<"2 1";
        else {
            if(n%2==0)
            {
                while(n--)
                    cout<<n+1<< " ";
            }
            else
            {
                int x=(n+1)/2;
                cout<<x<<" ";
                int y=n;
                for(int i=0;i<n;++i)
                {
                    if(y==x)
                    {
                        y--;
                        continue;
                    }
                    cout<<y--<<" ";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
 