#include<iostream>
#include<vector>
using namespace std;

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

//code for MMI
int modInverse(int a,int m){

    vector<int> result = extendedgcd(a,m);
    int x= result[0];
    int gcd= result[2];

    if(gcd!=1){
        cout<<"MMI doesn't exist"<<endl;
        return -1;
    }
    int ans =(x%m+m)%m;//preventing x to become negative here ,{1,2,3,......m-1 } range only
    return ans;

}



int main(){
    int a,m;
    cin>>a>>m;

    //a x + b y = gcd(a,b)
    //vector <int> result= extendedgcd(a,b);
    int ans = modInverse(a,m);
    if(ans!=-1){
        cout<<"MMI : "<<ans<<endl;
    }
    return 0;
}