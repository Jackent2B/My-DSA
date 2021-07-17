#include <bits/stdc++.h>
using namespace std;

//Method 2 : Better method (Time complexity : O(N))
int longestAlternativeSubSequence(int arr[], int n){
	
	int inc = 1;
	int dec = 1;

	for (int i = 1; i < n; ++i)
	{
		if(arr[i] > arr[i-1])
			inc = dec + 1;
		else if(arr[i] < arr[i-1])
			dec = inc + 1 
	}
	return max(inc,dec);
}

//Method 1: using DP( Time complexity: O(N*N))
// The approach is based on Longest Increasing subseqence

int longestAlternativeSubSequence(int arr[], int n){
	if(n==1)
		return 1;

	int dp[n][2];

	// Initialising all values with 1
	for (int i = 0; i < n; ++i)
		dp[i][0] = dp[i][1] = 1;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr[i]>arr[j])
				dp[i][0] = max(dp[i][0], dp[j][1] + 1);
			else if(arr[i]<arr[j])
				dp[i][1] = max(dp[i][1], dp[j][0] + 1);
		}
	}

	int ans = 1;
	for (int i = 0; i < n; ++i)
		ans = max(ans, max(dp[i][0], dp[i][1]));

	return ans;
}

int main(){
	
	int arr[] = {1,17,5,10,13,15,10,5,16,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<longestAlternativeSubSequence(arr,n);
	return 0;
}