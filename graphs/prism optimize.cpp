#include<bits/stdc++.h>
using namespace std;

// TC: O(N*logN)


int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int u,v,wt;
	for(int i = 0; i<m ; i++){
		cin >> u >> v >> wt;
		adj[u].push_back({v,wt});
		adj[v].push_back({u,wt});
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; parent[i] = -1;
    
    // Min Heap to get the smallest element on top. 
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
 
    key[0] = 0; 
    parent[0] = -1; 
    // pair = {key value, index}
    pq.push({0, 0});
    for (int count = 0; count < N - 1; count++)
    { 
        int temp = pq.top().second; 
        pq.pop(); 
        
        mstSet[temp] = true; 
        
        for (auto it : adj[temp]) {
            int node = it.first;
            int wt = it.second;
            if (mstSet[node] == false && wt < key[node]) {
                parent[node] = temp;
				key[node] = weight; 
                pq.push({key[node], node});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}