#include <bits/stdc++.h>
using namespace std;

// Reference : tech Dose (very nice video)

void dfs(int node, vector<int> adjlist[], vector<int> &storeDFS, vector<int> &vis){
	
	storeDFS.push_back(node);
	vis[node] = 1;

	for(auto i: adjlist[node]){
		if(!vis[i]){
			dfs(i, adjlist, storeDFS, vis);
		}
	}
}

int main(){

	int n,m;
	cin>>n>>m;

	if(m<n-1)
		cout<<"-1";
	else
	{
		vector <int> adjlist[n];

		for(int i=0; i<m; i++){
			int v,u;
			cin>>v>>u;
			adjlist[u].push_back(v);
			adjlist[v].push_back(u);
		}

		// Count of components
		int count = 0;
		vector<int> storeDFS;
		vector<int> vis(n,0);

		for(int i = 0; i<n; i++){
			if(!vis[i]){
				count++;
				dfs(i, adjlist, storeDFS, vis);
			}		
		} 

		// for (int i = 0; i < storeDFS.size(); ++i)
		// 	cout<<storeDFS[i]<<" ";
		// cout<<endl;

		cout<<"No. of components are: " << count << endl;

		int redundatEdges = 0;
		redundatEdges = m - ((n-1) - (count-1));
		if(redundatEdges >= count-1)
			cout<<count-1;
		else if(redundatEdges < count-1)
			cout<< "-1";

	}

	return 0;
}