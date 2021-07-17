#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	// 'n' represnets no. of nodes and 'm' represents no. of edges
	cin>>n>>m;

	// Declare the adjacency matrix
	int adj[n+1][m+1];
	
	//initialising all elements to zero
	memset(adj,sizeof(adj),0);
	
	//take edges as input
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}

	return 0;
}
