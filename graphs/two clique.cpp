#include <bits/stdc++.h>
using namespace std;

//Reference: Code Library

bool isBipartite(int src,vectore<int> complAdjlist[], int v){

	queue<int> q;
	q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}

bool checkBipartite(vector<int> complAdjlist[], int v){
	
	int color[v];
	memset(v, sizeof(v), -1;)

	for (int i = 0; i < v; ++i)
	{
		if(color[i] == -1){
			if(!isBipartite(i,complAdjlist,v))
				return false;
		}
	}
	return true;
}

int main(){
	int v,e;
	cin>>v>>e;

	vector<int> adjlist[v];
	for (int i = 0; i < e; ++i)
	{
		int u,v;
		cin>>u>>v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}


	//complementing the graph
	vector<int> complAdjlist[v];
		
	vector <int> temp(v,0);
	
	for(int i = 0; i<v; i++){
		temp[i] = 1;
		for(auto it: adjlist[i]){
			temp[it] = 1;
		}
		for (int j = 0; j < v; j++)
		{
			if(adjlist[j] == 0){
				complAdjlist[i].push_back(j);
				complAdjlist[j].push_back(i);	
			}
		}
	}

	if(checkBipartite(complAdjlist,v))
		cout<<"Yes, Two cliques are possible"<<endl;
	else
		cout<<"No, Two cliques are NOT possible"<<endl;

	return 0;
}