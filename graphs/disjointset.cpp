#include <bits/stdc++.h>
using namespace std;

//TC: O(4alpha) == O(4) i.e nearly constant
//SC: O(N + N) == O(N)  (parent[], rank[])

int parent[1e7];
int rank[1e7];


// Make parent of each node to be itself and their rank to be '0'
void makeset(int n){
 	for (int i = 1; i <= n; ++i)
	{
		parent[i] = i;
		rank[i] = 0; 
	}
}

int findParent(int node){
	if(parent[node] = node)
		return node;

	//Path compression
	return parent[node] = findParent(parent[node]);
}


void unionThem(int u, int v){
	u = findParent(u);
	v = findParent(v);

	if(rank[u] < rank[v])
		parent[u] = v;
	else if(rank[v]<rank[u])
		parent[v] = u;
	// If ranks of both are same
	else{
		parent[v] = u;
		rank[u]++;
	}
}

int main(){
	int n;
	cin>>n;
	makeset(n);
	int m;
	cin>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		unionThem(u,v);
	}
	//Example: check if 2 and 3 belongs to same component or not
	if(findParent(2) == findParent(3))
		cout<<"Yes they belongs to same component"<<endl;
	else
		cout<<"No they do not belongs to same component"<<endl;
	return 0;
}