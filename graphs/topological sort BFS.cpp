#include <bits/stdc++.h>
using namespace std;

//Note: Topological sort is only valid for DAG(Directed Acyclic graphs)graphs

vector<int> topologicalSortBFS(int n, vector<int> adjlist[]){

	queue <int> q;
	vector<int> indegree(n,0);

	// To calculate Indegree of each node
	for(int it = 0; it<n; it++){
		for(auto i: adjlist[it]){
			indegree[i]++;
		}
	}

	for(int i =0; i<n; i++){ 
		if(indegree[i]==0)
			 q.push(i);
	}

	vector<int> ans;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for(auto i: adjlist[x]){
			indegree[i]--;
			if(indegree[i]==0)
				q.push(i);
		}
	}
	return ans;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector <int> adjlist[n];
	for (int i = 0; i < m; ++i)
	{
	    int u,v;
	    cin>>u>>v;
		adjlist[u].push_back(v);
	}
	vector<int> ans = topologicalSortBFS(n,adjlist);
	for(int i=0; i<ans.size(); i++)
	    cout<<ans[i]<<" ";
	return 0;
}