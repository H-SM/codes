#include<bits/stdc++.h>
#define N 1000000 
#define ll long long 
using namespace std;

void primeSieve(vector <int> &sieve){
    //Mrak 1 and 0 as not prime
    sieve[1]=sieve[0]=0;

    //initially you can say all odd numbers as prime 
    for(int i=3;i<=N;i+=2){
        sieve[i]=1;
    }//even numbers can never be prime

    //start marking from 2 and mark multiple as not prime
    for(ll i=3;i<=N;i++){
        
        if(sieve[i]){
            for(ll j=i*i;j<=N;j=j+i){//i*i is the optimization
               //marking j as not prime 
                sieve[j]=0;
            }
        }
    }
}

int main()
{
    vector <int> sieve(N,0);//fill constructor 
    primeSieve(sieve);
    for(int i=0;i<=100;i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
        
    }
    cout<<endl;
    return 0;
}