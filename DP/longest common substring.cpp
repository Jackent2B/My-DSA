#include <bits/stdc++.h>
using namespace std;

int lcSubstr(string s1, string s2, int m, int n){

	int dp[m+1][n+1];

	int ans = 0;
	for(int i=0; i<m+1; i++){
		for (int j = 0; j < n+1; j++)
		{
			if(i == 0 || j==0)
				dp[i][j] = 0;
			else if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans,dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	return ans;
}

int main(){
	string s1 = "ABCDGH";
	string s2 = "ACDGHR";
	int m = s1.length();
	int n = s2.length();
	lcSubstr(s1,s2,m,n);
	return 0;
}