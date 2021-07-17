#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathBFS(int V, vector<int> adj[], int src){
        
    queue<int> q;
    vector<int> dist(V);
    for(int i=0; i<V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto i: adj[x]){
            if(dist[x] + 1< dist[i]){
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
    return dist;
}


int main(){
    int tc;
    cin >> tc;
    // for multiple graphs
    while(tc--){
        int V, E;
        cin >> V >> E;

        vector<int> adj[V+1];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        int src = 0;
        vector<int> ans = shortestPathBFS(V, adj, src);

        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}