#include <bits/stdc++.h>
using namespace std;

bool cycle_detection(int node, vector<int> &vis, vector<int> adj[]){

	queue<pair<int,int>> q;
	q.push({node,-1});
	vis[node] = 1;

	while(!q.empty()){
		int x = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(auto it: adj[x]){
			if(!vis[it]){
				q.push({it,x});
				vis[it] = 1;
			}
			else{
				if(parent != it){
					return true;
				};
			}
		}
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

	for(int i=0; i<N; i++){
		if(!vis[i]){
			if(cycle_detection(i,vis,adj)){
				cout<<"Cycle Found";
				break;
			}
		}
	}

	return 0;
}