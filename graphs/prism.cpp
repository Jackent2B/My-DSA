#include <bits/stdc++.h>
using namespace std;

// TC: O(N*N)

int main(){

	int n,m;
	cin>>n>>m;

	vector<pair<int,int>> adjlist[n];

	for (int i = 0; i < m; ++i)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		adjlist[u].push_back({v,wt});
		adjlist[v].push_back({u,wt});	
	}

	int parent[n];
	int key[n];
	bool inMST[n];

	for (int i = 0; i < n; ++i)
	{
		parent[i] = -1;
		key[i] = INT_MAX;
		inMST[i] = false;
	}

	parent[0] = -1;
	key[0] = 0;

	// MST always has only n-1 edges.
	for(int i=0; i<n-1; i++){

		int mini = INT_MAX;
		int temp;
		
		for(int i = 0; i<n; i++){
			if(key[i] < mini && inMST[i] == false){
				mini = key[i];
				temp = i;
			}
		}

		inMST[temp] = true;

		for(auto i: adjlist[temp]){
			int node = i.first;
			int wt = i.second;
			if(inMST[node] == false && wt < key[node]){
				parent[node] = temp
				key[node] = wt ;
			}
		}
	}


	for(int i = 1; i < n; ++i)
		cout<<parent[i]<<" "<<i<<" ";

	return 0;
}