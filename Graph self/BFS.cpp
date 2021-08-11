#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int> &vis, vector<int> adj[]){

	queue<int> q;
	q.push(node);
	vis[node] = 1;

	while(!q.empty()){
		int x = q.front();
		cout<<x<<" ";
		q.pop();
		for(auto it: adj[x]){
			if(!vis[it]){
				q.push(it);
				vis[it] = 1;
			}
		}
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