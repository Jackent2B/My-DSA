#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[]){
	cout<<node<<" ";
	vis[node] = 1;

	for(auto it: adj[node]){
		if(!vis[it])
			dfs(it, vis, adj);
	}
	return;
}

int main(){
	int N,E;
	cin>>N>>E;
	vector<int> adj[N];
	vector<int> vis(N,0);

	for (int i = 0; i < E; i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	int no_of_components = 0;
	for(int i=0; i<N; i++){
		if(!vis[i]){
			bfs(i,vis,adj);
			cout<<endl;
			no_of_components++;
		}
	}
	cout<<endl;
	cout<<"No of components are: "<< no_of_components;

	return 0;
}