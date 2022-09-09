#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int y,w;
    cin>>y;
    cin>>w;
    int x= max(y,w);
    x=6-x;
	string o[] = {"1/6","1/3", "1/2", "2/3", "5/6", "1/1"};
	cout << o[x];
    return 0;
}