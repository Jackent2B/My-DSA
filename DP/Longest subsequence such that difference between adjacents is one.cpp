#include <bits/stdc++.h>
using namespace std;

// Algorithm: Based on LIS

int longestSubseqWithDiffOne(int arr[], int n){

	int dp[n];
    for (int i = 0; i< n; i++)
        dp[i] = 1;
    int result = 1;
 	//10, 9, 4, 5
    for (int i=1; i<n; i++)
    {
        for (int j=0; j<i; j++)
        {
            // If the element is consecutive then
            // consider this subsequence and update
            // dp[i] if required.
            if ((arr[i] == arr[j]+1) || (arr[i] == arr[j]-1))
                dp[i] = max(dp[i], dp[j]+1);
        }
        result = max(result,dp[i]);
    }
 
    // // Longest length will be the maximum value
    // // of dp array.
    // int result = 1;
    // for (int i = 0 ; i < n ; i++)
    //     if (result < dp[i])
    //         result = dp[i];
     return result;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 3, 2};
	// Longest subsequence with one difference is
    // {1, 2, 3, 4, 3, 2}
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << longestSubseqWithDiffOne(arr, n);
    return 0;
}