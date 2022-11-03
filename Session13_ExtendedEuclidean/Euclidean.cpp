#include<iostream>
#include<vector>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
/*
//{x,y}
vector<int> extendedgcd(int a ,int b){
    if(b==0){//return values of x and y
        return {1,0};
    }
    vector<int> result=extendedgcd(b,a%b);
    
    //after recurisive call is over
    int smallx=result[0];
    int smally=result[1];

    int x=smally;
    int y=smallx-(a/b)*smally;
    return {x,y};
}
*/
//modified version which gives gcd as well
//{x,y,gcd}
//IMPORTANT 
vector<int> extendedgcd(int a ,int b){
    if(b==0){//return values of x and y
        return {1,0,a};
    }
    vector<int> result=extendedgcd(b,a%b);
    
    //after recurisive call is over
    int smallx=result[0];
    int smally=result[1];
    int gcd=result[2];
    int x=smally;
    int y=smallx-(a/b)*smally;
    return {x,y,gcd};
}

int main(){
    int a,b;
    cin>>a>>b;

    //a x + b y = gcd(a,b)
    vector <int> result= extendedgcd(a,b);
    cout<<result[0]<<" and "<<result[1]<<" and GCD:"<<result[2]<<endl;

    cout<<"From standard Euclid's Algorithm : GCD -> "<<gcd(a,b)<<endl;
    return 0;
}