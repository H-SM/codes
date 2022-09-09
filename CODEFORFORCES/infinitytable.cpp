#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    
    int t,k,n;
    cin>>t;
    while(t--){
    cin>>k,n=ceil(sqrt(k));
	if(n*n-k<n)
	    cout<<n<<" "<<n*n-k+1<<endl;
	else 
        cout<<n-(n*n-k-n)-1<<" "<<n<<endl;
    }
    return 0;
}