#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define int long long int 
#define F first
#define S second 
#define pb push_back



int32_t main(){
   int n;
   cin>>n;
   vector<int> primes ={2,3,5,7,11,13,17,19,23,29};
   int m=primes.size();
    int ans=0;
   //using bit manupilation to make all subsets out of these primes 
    for(int i=1;i<(1<<m);i++){
         int lcm=1;
        for(int j=0;j<m;j++){
            //if jth bit of ith element is set then include it 
            if((i>>j)&1){
                lcm *=primes[j];
                //cout<<primes[j]<<" ";
            } 
        }
if(__builtin_popcount(i)%2==0){
    ans-=(n/lcm);
}
else{
    ans+=(n/lcm);
}
cout<<ans<<endl;
}
return 0;
}