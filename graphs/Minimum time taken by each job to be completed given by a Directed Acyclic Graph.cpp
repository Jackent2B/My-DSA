#include <bits/stdc++.h>
using namespace std;

void minimumTimeTaken(vector<int> adjlist[], int n){

	vector<int> indegree(n+1,0);
	vector<int> jobtime(n+1,0);

	for(int i=1; i<=n; i++){
		for(auto it: adjlist[i]){
			indegree[it]++;
		}
	}

	queue<int> q;
	for(int i=1; i<=n; i++){
		if(indegree[i]==0){
			q.push(i);
			jobtime[i] = 1;
		}
	}

	vector<int> ans;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for(auto i: adjlist[x]){
			indegree[i]--;
			if(indegree[i] == 0){
				jobtime[i] = jobtime[x]+1;
				q.push(i);
			}
		}
	}

	//NOTE: Important
	// vector<int> ans will return the nodes in topological sort
	//jobstime[] will return the time that we want in this ans;

	for (int i = 1; i <= n; ++i)
		cout<<jobtime[i]<<" ";
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<int> adjlist[n+1];
	for(int i=0; i<m; i++){
		int u,v;
		cin>>u>>v;
		adjlist[u].push_back(v);
	}
	minimumTimeTaken(adjlist,n);
	
	return 0;
}