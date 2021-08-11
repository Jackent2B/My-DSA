#include <bits/stdc++.h>
using namespace std;

bool checkForCycle(int i, vector<int> adjlist[], vector<int> &vis){
	stack<pair<int,int>> s; 
    s.push({i,-1}); 
    vis[i] = 1; 

    while(!s.empty()) {
        
        int node = s.top().first;
        int par = s.top().second;
        s.pop(); 

        for(auto it : adjlist[node]) {
            if(!vis[it]) {
                s.push({it,node}); 
                vis[it] = 1; 
            }
            else if(par != it){
            	return true;
            }
        }
    }
	return false;
}

bool iscycle(int n, vector<int> adjlist[]){
	
	vector<int> vis(n+1,0);
	for (int i = 1; i <= n; ++i)
	{
		if(!vis[i]){	
			if(checkForCycle(i,adjlist,vis))
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