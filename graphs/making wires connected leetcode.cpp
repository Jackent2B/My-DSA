class Solution {
void dfs(int node, vector<int> adjlist[], vector<int> &vis){	
	vis[node] = 1;
	for(auto i: adjlist[node]){
		if(!vis[i]){
			dfs(i, adjlist, vis);
		}
	}
}
public:    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if(m<n-1)
            return -1;
        vector <int> adjlist[n];

		for(int i=0; i< m; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

		// Count of components
		int count = 0;
		vector<int> vis(n,0);

		for(int i = 0; i<n; i++){
			if(!vis[i]){
				count++;
				dfs(i, adjlist,vis);
			}		
		}
        int redundatEdges = 0;
        // To get the no. of redundant edges
		redundatEdges = m - ((n-1) - (count-1));
		if(redundatEdges >= count-1)
			return count-1;
		return -1;
    }
};