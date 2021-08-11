#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int node,int parent, vector<int> adjlist[], vector<int> &vis){
	vis[node] = true;
	for(auto it: adjlist[node]){
		if(!vis[it]){
			if(checkForCycle(it,node,adjlist,vis))
			return true;
		}
		else{
			if(it!=parent)
				return true;
		}
	}
	return false;
}

bool iscycle(int n, vector<int> adjlist[]){

	// considering 1 based indexing	
	vector<int> vis(n+1,0);
	for (int i = 1; i <= n; ++i)
	{
		if(!vis[i]){	
			if(checkForCycle(i,-1,adjlist,vis))
				return true;
		}
	}
	return false;
}

int main(){
	int n,e;
	cin>>n>>e;
	vector<int>adjlist[n+1];
	for(int i = 0; i<e; i++){
		int u,v;
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	bool ans=iscycle(n, adjlist);
	if(ans) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
}