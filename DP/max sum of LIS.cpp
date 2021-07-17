#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n){

	int dp[n];
	int maxSum = arr[0];
	dp[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = arr[i];
		for (int j = 0; j < i; ++j)
		{
			if(arr[i]>arr[j])
				dp[i] = max(dp[j]+arr[i],dp[i]);
		}
		maxSum = max(maxSum,dp[i]);
	}
	return maxSum;
}

int main(){
	
	int arr[] = {1, 101, 2, 3, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<LIS(arr,n);

	return 0;
}