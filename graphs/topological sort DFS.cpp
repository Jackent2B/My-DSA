#include <bits/stdc++.h>
using namespace std;

//Note: Topological sort is only valid for DAG(Directed Acyclic graphs)graphs

void topologicalSortDFS(int node, vector<int> &vis, stack<int> &st, vector<int> adjlist[]){
	vis[node] = 1;
	for(auto i: adjlist[node]){
		if(!vis[i]){
			topologicalSortDFS(i,vis,st,adjlist);
		}
	}
	st.push(node);
}

vector<int> topologicalSort(int n, vector<int> adjlist[]){
	stack<int> st;
	vector<int> vis(n,0);
	for (int i = 0; i < n; ++i)
	{
		if(!vis[i]){
			topologicalSortDFS(i,vis,st,adjlist);
		}
	}
	vector<int> ans;
	while(!st.empty()){
		int x = st.top();
		st.pop();
		ans.push_back(x);
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
	vector<int> ans = topologicalSort(n,adjlist);
	for(int i=0; i<ans.size(); i++)
	    cout<<ans[i]<<" ";
	return 0;
}