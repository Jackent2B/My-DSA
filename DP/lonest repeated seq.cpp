#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

int LCS(string s1, string s2, int m, int n){
	
	if(m == 0 || n == 0)
		return 0;
	else if (t[m][n] != -1)
		return t[m][n];
	else if(s1[m-1] == s2[n-1] && m!=n)
		return t[m][n] = 1 + LCS(s1,s2,m-1,n-1);
	else
		return t[m][n] = max(LCS(s1,s2,m-1,n),LCS(s1,s2,m,n-1));
}

int main(){

	memset(t , -1, sizeof(t));
	string s1 = "ABCDGH";
	string s2 = "AEDFHR";
	int m = s1.length();
	int n = s2.length();
	cout<<LCS(s1,s2,m,n);
	return 0;
}