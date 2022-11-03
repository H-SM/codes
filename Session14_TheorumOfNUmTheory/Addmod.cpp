#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int P=1e9+7, N=1e5;
int fact[N];
int addm(int x, int y){
    return(x+y)%P;
}
int subm(int x, int y){
    //return(x-y)%P;
    return((x-y)%P+P)%P;
}
int mulm(int x, int y){
    //cant fit in int eg- 10^9*10^5 thus making it long long int 
    return(x*y)%P;
}
int powrm(int x, int y){
    int res=1;
    while(y){
        if(y&1) res =mulm(res,x);
        y/=2;
        x= mulm(x,x);
    }
    return res; 
}
int inv(int x){
    return powrm(x,P-2);
}
int divm(int x, int y){
    return mulm(x,inv(y));
}


void caluclate_factorials(){
    fact[0]=1;
    for (int i=1;i<N ;i++){
        fact[i]=mulm(fact[i-1],i);
    }
}


int ncr(int n,int r){
    return mulm(mulm(fact[n],inv(fact[r])),inv(fact[n-r]));

}
int32_t main(){
    cout<<addm(3,5)<<endl;
    cout<<subm(-3,5)<<endl;//but need to be 2 , gives -3 thus the change there 
    cout<<mulm(324,324)<<endl;
    cout<<divm(56,2)<<endl;
    caluclate_factorials();
    cout<<fact[5]<<endl;
    cout<<ncr(5,2)<<endl;
    cout<<ncr(5778,123)<<endl;///supports till 1e5
    return 0;
}