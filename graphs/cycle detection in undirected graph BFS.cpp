#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, vector<int> adj[], vector<int>& visited)
{
    // Create a queue for BFS
    queue<pair<int,int>> q;
 
    visited[s] = true;
    q.push({s, -1});
 
    while (!q.empty()) {
 
        int node = q.front().first;
        //parent == parent Node
        int parent = q.front().second;
        q.pop();
 
        for (auto it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push({it, node});
            }
            else if (parent != it)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int>adj[]){
    vector<int> vis(V+1, 0); 
    for(int i = 0;i<V;i++) {
        if(!vis[i]) {
            if(checkForCycle(i, adj, vis)) return true; 
        }
    }
    
    return false; 
}


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V+1];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool ans = isCycle(V, adj);
		if(ans)	cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}