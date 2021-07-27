#include <bits/stdc++.h>
using namespace std;

// ref: pepcoding

int numericKeypad(int n){
	if(n==0)
	    return 0;

	unordered_map<int, vector<int>> mp;
	mp[0] = {0,8};
	mp[1] = {1,2,4};
	mp[2] = {1, 2, 5, 3};
	mp[3] = {2, 3, 6};
	mp[4] = {1, 4, 5, 7};
	mp[5] = {4, 2, 6, 8, 5};
	mp[6] = {3, 5, 9, 6};
	mp[7] = {4, 7, 8};
	mp[8] = {7, 5, 9, 8, 0};
	mp[9] = {6, 8, 9}; 

	int dp[n+1][10];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < 10; j++){
			if(i==1){
				dp[i][j] = 1;
			}
			else{
				vector<int> v = mp[j];
				for (int a = 0; a < v.size(); a++)
				{
					int x = v[a];
					dp[i][j] += dp[i-1][x]; 
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i<10; i++){
		ans = ans + dp[n][i];
	}
	return ans;
}
int main(){
	int n = 1;
	cout<<numericKeypad(n);
	return 0;
}