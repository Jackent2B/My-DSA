#include <bits/stdc++.h>
using namespace std;

bool cycle_detection(int node,int parent, vector<int> &vis, vector<int> adj[]){
	//cout<<node<<" ";
	vis[node] = 1;

	for(auto it: adj[node]){
		if(!vis[it]){
			if(cycle_detection(it,node,vis, adj))
				return true;;
		}
		else if(parent != it)
		  return true;
	}
	return false;
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
			if(cycle_detection(i,-1,vis,adj)){
				cout<<"Cycle detected";
				break;
			}
		}
	}
	return 0;
}