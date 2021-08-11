#include <bits/stdc++.h>
using namespace std;

int in[101], low[101];
int timer = 0;
// Nodes are starting from 1
vector<int> adjlist[100+1];
int vis[100+1]={0};

void dfs(int node, int parent){
	
	vis[node] = 1;
	in[node] = timer;
	low[node] = timer;
	timer++;

	for(auto it: adjlist[node]){
		if(it == parent)
			continue;

		if(vis[it]==1){
			// edge node-child is a backedge
			low[node] = min(low[node],low[it]);
		}
		else{
			// edge node-child is a forward edge
			dfs(it,node);
			// When it will revert back
			if(low[it] > in[node])
				cout<< node <<" - "<<it<< " is a Bridge ";
			low[node] = min(low[node], low[it]);
		}

	}

}

int main(){
	int n,m;
	cin>>n>>m;

	for(int i = 0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	dfs(1,-1);
	return 0;
}