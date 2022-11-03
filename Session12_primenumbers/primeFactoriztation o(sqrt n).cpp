#include<iostream>
#include<vector>
using namespace std;



void factorization(int n){

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count =0;
            while(n%i==0){
                n=n/i;
                count++;
            }
            cout<<i<<"^"<<count<<",";
        }

    }
    //out of the loop 
    if(n!=1)
    cout<<n<<"^1";
    cout<<endl;
}
/*
Optimized Approach:
Obs : Once N is reduced to prime number , the 
only factor that number will be the number itself.

If number doesn't have any factor till sqrt(n)
then it is a prime number 
run the loop to sqrt(n)
if no divisor for a sub problem then exit the loop 
*/
int main(){
    int x;
    cin>>x;
	factorization(x);
	return 0;
}