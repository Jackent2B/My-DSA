#include <bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;

    //For Undirected Graph
    vector<int> adjlist[n+1];

    //For undirected weighted Graph
    vector<pair<int,int>> adjlist[n+1];


    // For Undirected graph
    for(int i=0; i<m; i++){

        int  u,v;
        cin>>u>>v;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    // For Directed graph
    for(int i=0; i<m; i++){

        int  u,v;
        cin>>u>>v;

        adjlist[u].push_back(v);
    }


    // For Undirected weighted graph
    for(int i=0; i<m; i++){

        int  u,v,wt;
        cin>>u>>v>>wt;

        adjlist[u].push_back({v,wt});
        adjlist[v].push_back({u,wt});
    }
    return 0;
}