#include<iostream>
#include<vector>
using namespace std;
#define N 100000
/* 
we make 1 array of primes upto 10^5 and make not primes in other using the prev array 
make sieve and store prime no. in 'primes' ok/.......
*/ 
int  sieveArr[N+1]={0};
vector <int> primes;

void sieve(){

    for(long long i=2;i<=N;i++){
        if(sieveArr[i]==0){
            primes.push_back(i);
            // mark the multiples of i as non prime 
            for ( long long j=i*i; j<=N;j+=i){
                sieveArr[j]=1;
            }
        }
    }
}


int main(){
    //precompute 
    sieve();
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m;
        cin>>n;
        vector<int> segment(n-m+1,0);

        for(auto p:primes){

            //stop when p^2 >n 
            if(p*p>n){
                break;
            }
            //otherwise find the nearest starting point 
            int start=(m/p)*p;
            // lets say p=2 and m=99 99/2 -> 48 

            //special case when start is smaller than m
            if(p>=m and p<=n){
                start= 2*p;
            }

            // start marking the numebers as not prime from start 
            for( int j = start; j<=n;j=j+p){
                if(j<m){
                    continue;
                }
                segment[j-m]=1;
                //marked as not prime 

            }

        }
        //primes marked as 0
        for(int i=m; i<=n;i++){
            if(segment[i-m]=0 and i!=1){
                cout<<i<<endl;
                
            }
        }
        cout<<endl;

    }return 0;

}