#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int y;
    cin>>y;
    int z=y+1;
    while(true){
    int num=z;
    bool visited[10] = {false};
    while (num)
    {
        if (visited[num % 10])
                break;

        visited[num%10] = true;
        num = num/10;
        }
    if (num == 0)
    {
        cout<<z<<endl;
        break;
    }
    z++;
    }
    return 0;
}