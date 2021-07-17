#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string a, string b, int m, int n){
	if(m != n)
		return false;

	unordered_map<char,char> connection;
	unordered_map<char, bool> visited;

	for (int i = 0; i < m; ++i)
	{
		char ch1 = a[i];
		char ch2 = b[i];

		if(connection.find(ch1) != connection.end()){
			if(connection[ch1] != ch2 )
				return false;
		}
		else{
			if(visited.find(ch2) != visited.end()){
				return false;
			}
			else{
				connection[ch1] = ch2;
				visited[ch2] = true;
			}
		}

	}

	return true;
}

int main(){
	string a = "aabca";
	string b = "xxyzx";
	cout<<isIsomorphic(a,b,a.length(),b.length());
	return 0;
}