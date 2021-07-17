#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<pair<int,int>> adj[], int src){
    vector <int> dis(n);
    for (int i = 0; i < n; ++i)
        dis[i] = INT_MAX;

    dis[src] = 0;
    queue <int> q;

    q.push(src);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto i: adj[x]){
            if(dis[x] + i.second < dis[i.first]){
                dis[i.first] = dis[x] + i.second;
                q.push(i.first);
            }
        }
    }
    return dis;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> adj[n]; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        adj[u].push_back({v, wt}); 
        adj[v].push_back({u, wt}); 
    }
    vector<int> dis = shortestPath(n, adj, 0); 
    for (int i = 0; i < n; ++i)
        cout<<dis[i]<<" ";
    return 0; 
}