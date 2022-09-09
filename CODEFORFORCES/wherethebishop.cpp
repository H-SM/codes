#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int sz=8;
struct Mat{
    int m[sz][sz];
    Mat(){
        memset(m,0,sizeof(m));
    }
};



int32_t main(){

    int t;
    cin>>t;
    while(t--){
    Mat chess;
    char c;
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            cin>>c;
           if(c=='#')
            chess.m[i][j]=1;
           else
           chess.m[i][j]=0;
        };
    }
    for(int i=1;i<sz-1;i++){
        for(int j=1;j<sz-1;j++){
            if(chess.m[i-1][j-1]==1&&chess.m[i+1][j-1]==1&&chess.m[i-1][j+1]==1&&chess.m[i+1][j+1]==1)
            cout<<i+1<<" "<<j+1<<endl;}}
    }
    return 0;
}