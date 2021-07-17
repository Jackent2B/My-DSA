#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<pair<int,int>> adj[], int source){

    // 1-indexed array for calculating shortest paths
    vector<int> dis(n+1);
    for (int i = 1; i <= n; ++i)
        dis[i+1] = INT_MAX;

    dis[source] = 0;

    // min-heap ; In pair => (dist,from)    
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    
    // (dist,from)
    pq.push({0,source});   
    
    while( !pq.empty() ){

        int dist = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        for(auto it: adj[x]){
            int num = it.first;
            int wt = it.second;
            if(dis[x] + wt < dis[num]){
                dis[num] = dis[x] + wt;
                pq.push({dis[num],num});
            }
        }
    }

    return dis;
}

int main(){
    int n, m;
    cin >> n >> m;
    // (node,wt)
    vector<pair<int,int>> adj[n+1]; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        adj[u].push_back({v, wt}); 
        adj[v].push_back({u, wt}); 
    }
    int source = 1;
    vector<int> dis = shortestPath(n, adj, source); 
    for (int i = 1; i <= n; ++i)
        cout<<dis[i]<<" ";
    return 0; 
}