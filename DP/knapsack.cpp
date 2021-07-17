#include <bits/stdc++.h>
using namespace std;

// Top Down
// int knapSack(int W, int wt[], int val[], int n){
//    	int dp[n+1][W+1];

// 	for (int i = 0; i < n+1; ++i)
// 	{
// 		for (int j = 0; j < W+1; ++j)
// 		{
// 			/* code */
// 			if(i==0 || j == 0){
// 				dp[i][j] = 0;
// 			}
// 			else if(wt[i-1]<=j){
// 				dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);	
// 			}
// 			else if(wt[i-1]>j){
// 				dp[i][j] = dp[i-1][j]; 
// 			}
// 		}
// 	}
// 	return dp[n][W];
// }

int t[1001][1001];
int knapSack(int W, int wt[], int val[], int n){
	if(n==0 || W == 0){
		return 0;
	}
	else if(t[n][W] != -1){
		return t[n][W];
	}
	else if(wt[n-1]<=W){
		return t[n][W] = max(val[n-1]+knapSack(W-wt[n-1], wt, val, n-1),knapSack(W, wt, val, n-1));	
	}
	else if(wt[n-1]>W){
		return t[n][W] = knapSack(W, wt, val, n-1); 
	}
}

int main(){
	memset(t, -1, sizeof(t));
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}