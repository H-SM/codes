#include<iostream>
using namespace std;
int main(){
    int x,i;
    cin>>x;
    i=2;
    while(i<=((x/2)+2))
    {
        if((x-i)%2==0)
        {
            cout<<"YES"<<endl;
            break;
        }
        i=i+2;
    }
    if(i==(x/2)+4)
        cout<<"NO"<<endl;
    return 0;
}