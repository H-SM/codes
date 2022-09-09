#include<bits/stdc++.h>
# include<iostream>
using namespace std;
void solve(){
   
   long long  n,p=0,t=0,k,j,s=0,l=0;
   string s1;
   //a[0]=4;a[1]=8;a[2]=15;a[3]=16;a[4]=23;a[5]=42;
   cin>>s1;
   n=s1.size();
   long long a[1000];
   vector<long long>V;
   for(k=0;k<n;k++)
  { if(s1[k]=='1')
   s++;
   else 
   {if(s!=0)
      V.push_back(s);
   s=0;l=1;}
  }
  //if(l==0)
    V.push_back(s);
//cout<<V.size();
sort(V.begin(),V.end());
 for(k=0;k<V.size();k++)
 {t+=V[V.size()-1-k];
 k++;}
 
  cout<<t<<"\n";
    
}
int main()
{ long long a;
 
cin>>a;
while(a--)
solve();
return 0;
}