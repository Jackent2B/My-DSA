#include <bits/stdc++.h>
using namespace std;

int t[101][101];
int editDistance(string s1, string s2, int m, int n){

	if(m == 0 )
		return n;
	if(n == 0 )
		return m;	

	if(t[m][n] != -1)
		return t[m][n];

	else if(s1[m-1] == s2[n-1]){
		return t[m][n] = editDistance(s1,s2,m-1,n-1);
	}

	else if(s1[m-1] != s2[n-1]){
		return t[m][n] =  1 + min(min(
							  editDistance(s1,s2,m-1,n), // Remove
							  editDistance(s1,s2,m,n-1)), // Insert
							  editDistance(s1,s2,m-1,n-1) // Replace
							 );	
	}

}

int main(){
	memset(t , -1, sizeof(t));
	string s1 = "geek";
	string s2 = "gesek";
	int m = s1.length();
	int n = s2.length();
	cout<<editDistance(s1,s2,m,n);
	return 0;
}