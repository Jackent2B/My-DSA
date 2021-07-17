// Reference : techdose
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis){

	vis[node] = 1;
	for(auto i : adj[node] ){
		if(!vis(i)){
			dfs(i, adj, vis);
		}
	} 

}

int main(){
	int n,e;

	cin>>n>>e;

	vector<int> adj[n];

	for(int i=0; i<n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n,0);
	vector<int> indegree(n,0);

	// Calculate Indegree
	for(int i=0; i<n; i++){
		for(auto it: adj[i]){
			indegree[it]++;
		}
	}

	// Finding a node with indegree > 0
	int x = -1;
	for(int i=0; i<n; i++){
		if(indegree[i]>0){
			x = i;
			break;	
		}
	}

	if(x==-1)
		cout<<"Eular graph";
	else{	
		dfs(x,adj,vis);

		// Checking Visited Array
		for(int i = 0; i<n; i++){
			if(vis[i] == 0){
				if(indegree[i]>0){
					cout<<"NOT a Eular Graph"<<endl;
				}
			}
		}	
	}


	// Count of Nodes having ODD Indegree
	int countOfODDIndegreeNode = 0;

	for(int i = 0; i<n; i++){
		if(indegree[i] %2 == 1)
			countOfODDIndegreeNode++;
	}

	if(countOfODDIndegreeNode == 0)
		cout<<"Its a Eular Graph";
	else if(countOfODDIndegreeNode == 0)
		cout<<"Its a Semi-Eular Graph";
	else
		cout<<"Not a Eular Graph";

	return 0;
}