
#include<iostream>
#include<vector>
using namespace std;
#define N 1000000
#define ll long long


void primeSieve(vector<int> &sieve){

	for(int i=1; i<=N; i++){
		sieve[i] = i;
	}
/*
Optimized Approach:
using Sieve 
we store smallest possible prime factor for that numuber like 4->2 8->2 15->3 18->3 11->11 2->2 <the smallest> after i^2 <optimization> 
*/
	//start from 2 to N
	for(ll i=2; i<=N; i++){
		//whether a no is prime 
		if(sieve[i]==i){

			for(ll j= i*i; j<=N; j = j + i){
				//mark of them if they are already not marked with the value i
				if(sieve[j]==j){
					sieve[j] = i;
				}
			}
		}
	}

}


vector<int> getFactorisation(int number, vector<int> &sieve){
	vector<int> factors;
	while(number!=1){
		factors.push_back(sieve[number]);
		number = number/sieve[number];
	}
	return factors;
}


int main(){

	//Prime Sieve (NLogLogN)
	vector<int> sieveArr(N+1,0);
	primeSieve(sieveArr);

	int number;
	cin>>number;
	// Method for multiple queries  (O(LogN))
	vector<int>  factors = getFactorisation(number,sieveArr);
	for(int f : factors){
		cout << f <<",";
	}

	return 0;
}