#include<iostream>
#include<vector>
using namespace std;



void factorization(int n){

    for(int i=2;i<=n;i++){
        if(n%i==0){
            int count =0;
            while(n%i==0){
                n=n/i;
                count++;
            }

            cout<<i<<"^"<<count<<",";
        }

    }
    cout<<endl;
}


int main(){
    int x;
    cin>>x;
	factorization(x);
	return 0;
}