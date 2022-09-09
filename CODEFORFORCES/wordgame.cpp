#include<bits/stdc++.h>
#include<iostream>
#define ll long long int 
#define print(a)          \
	for (auto x : a)      \
		cout << x << " "; \
	cout << endl
using namespace std;
//https://codeforces.com/problemset/problem/1722/C
int main()
{
    long long int t;
    cin>>t;
     while(t--)
    {
        int n;
        cin>>n;
        ll ma=3;
        //std::map<int,std::map<int,std::string>> m;
        //to note this step here

        map<string,vector<ll>>m;
        vector<vector<string>>vp(3,vector<string>(n)); //showing conflicted declaration???

        for (ll i = 0; i < 3; i++) {
            vector<string> sp;
        for (ll j = 0; j < n; j++) {
            string s=NULL;
            cin>>s;
            m[s].push_back(i);
            sp.push_back(s);
        }vp[i-1]=sp;
        }

        vector<ll>res;

        for(ll k=0;k<ma;k++){
            vector<string>p1=vp[k];
            ll ans=0;
            for(auto j:p1){
                ll sz=m[j].size();
                if(sz==1)ans+=3;
                else if(sz==2)ans+=1;
                else continue;
            }
            res.push_back(ans);
        }
        print(res);
    }
        
    return 0;
}