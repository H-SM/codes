#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long 
//this dfs will give the size of the tree from the node where its called
int dfs(int u, int parent,vector<pair<int,int>>adj[],ll &ans,int N){
    int currentTreeSize=1;
    for(auto p: adj[u]){
        int v=p.first;
        int wt=p.second;
        //Skip the parent node acting as neighbour for this node
        if(v==parent){
            continue;
        }

        int childTreeSize= dfs(v,u,adj,ans,N);
        int edgeContribution= 2* min(childTreeSize,N-childTreeSize)*wt;
        ans+=edgeContribution;
        //update tree sizwe adding childtreesize
        currentTreeSize+=childTreeSize;
    }
    return currentTreeSize;
}
int main(){
    int test;
    cin>>test;
    int n,u,v,w;

    //graph              array of vector
    vector<pair<int,int>>adj[100005];
    int tc=1;
    while(tc<=test){
        cin>>n;
        //rest adj list before every tc
        for (int i=1;i<=n;i++){
            adj[i].clear();
        }//numbering in prob is from 1 not 0
        
        //scan the graph
        for(int i=i;i<n-1;i++){
            cin>>u>>v>>w;
            adj[u].puch_back({v,w});
            adj[v].push_back({u,w});

        }

        //dfs
        ll ans=0;
        dfs(1,-1,adj,ans,n);

        cout<<"Case #"<<tc<<": "<<ans<<endl;
        tc=tc+1;

    }
    return 0;}