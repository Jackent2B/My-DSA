#include<bits/stdc++.h>
using namespace std;

// vector<int> dfsOfGraph(int n, vector<int> adjlist[]){

//     vector<int> dfs;
//     vector<int> vis(n+1,0);
//     for (int i = 1; i <= n; ++i)
//     {
//         if(!vis[i]){
//             stack<int> s; 
//             s.push(i); 
//             vis[i] = 1; 

//             while(!s.empty()) {
//                 int node = s.top();
//                 s.pop(); 
//                 dfs.push_back(node); 
//                 for(auto it : adjlist[node]) {
//                     if(!vis[it]) {
//                         s.push(it); 
//                         vis[it] = 1; 
//                     }
//                 }
//             }
//         }
//     }
//     return dfs;
// }


//Recursive
void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
    storeDfs.push_back(node); 
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, storeDfs); 
        }
    }
}

vector<int>dfsOfGraph(int V, vector<int> adj[]){
    vector<int> storeDfs; 
    vector<int> vis(V+1, 0); 
  for(int i = 1;i<=V;i++) {
    if(!vis[i]) dfs(i, vis, adj, storeDfs); 
  }
    return storeDfs; 
}

int main(){
    int tc;
    cin >> tc;
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

        vector<int>ans=dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}