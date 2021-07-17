// ALGORITHM:
// 1) Create a graph g with number of vertices equal to the size of alphabet in the given alien language. For example, if the alphabet size is 5, then there can be 5 characters in words. Initially there are no edges in graph.
// 2) Do following for every pair of adjacent words in given sorted array. 
// …..a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters. 
// …..b) Create an edge in g from mismatching character of word1 to that of word2.
// 3) Print topological sorting of the above created graph.

#include <bits/stdc++.h>
using namespace std;

void topologicalSort(char x,stack<char> st,vector<char> &vis, vector<char> adj[]){
	vis[x] = 1;
	for(auto i: adj[x]){
		if(!vis[i])
			topologicalSort(i,st,vis,adj);
	}

	st.push(x); 
}

void compareAndADDEdge(string s1, string s2, vector<char> adj[]){
	
	int i=0;
	int j=0;
	while(i < s1.length() && j < s2.length()){
		if(s1[i] != s2[j]){
			adj[s1[i]].push_back(s2[j]);
			break;
		}
		i++;
		j++;
	}
}

void alienOrder(vector<string> &words, int n, int k){

	vector<char> adj[k];
	for(int i=0; i<n-1; i++){
		string s1 = words[i];
		string s2 = words[i+1];
		compareAndADDEdge(s1,s2,adj);
	}
	
	vector <char> vis(k,0);

	stack<char> st;
	for (int i = 1; i <= k; ++i){
		char x = (char)('a' + i - 1);
		if(!vis[x]){
			topologicalSort(x,st,vis,adj);
		}
	}
	
	while(!st.empty()){
		char c = st.top();
		st.pop();
		cout<<c<<" ";
	}	

}

int main(){
	int n,k;
	cin>>n>>k;

	vector <string> words;
	for(int i = 0; i<n; i++){
		string s;
		cin>>s;
		words.push_back(s);
	}
	alienOrder(words,n,k);
	return 0;
}