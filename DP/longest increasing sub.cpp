#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n){

	int dp[n];
	dp[0] = 1;
	int ans = 1;
	for (int i = 1; i < n; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if(arr[i]>arr[j])
				dp[i] = max(dp[j]+1,dp[i]);
		}
	ans = max(ans,dp[i]);
	}
	return ans;
}

int main(){
	
	int arr[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<LIS(arr,n);

	return 0;
}