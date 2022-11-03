#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int N =1e5;

void calculate_totient(){
    vector<bool> pr(N,true);
    vector<int> tot(N);
    for(int i=2;i<N; i++ ){
        for(int j=i*i;j<N ;j+=i){
            pr[j]=false;
        }
    }
    iota(tot.begin(),tot.end(),0);//fills numebr wiht itself , index filling
    for(int i=2;i<N;i++ ){
        if(pr[i]==true){

            //multiples of prime 
            for(int j=i;j<N;j+=i ){
                //j is divisible by i <multiple of i>
                //i is prime
                tot[j]/=i;
                tot[j]*= (i-1);
            }
        }
    }
    for(int i=1;i<10;i++){
        cout<<i<<" "<<tot[i]<<endl;
    }
}
//o(2. n log log n)
//we are moving with multiples of i not divisible of j 
int32_t main(){
    
    calculate_totient();
    return 0;
}