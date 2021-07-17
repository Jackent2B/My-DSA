#include <bits/stdc++.h>
using namespace std;
 
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    sort(arr, arr+N);
 
    int dp[N];
    dp[0] = 0;
 
    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i-1];
 
        if (arr[i] - arr[i-1] < K)
        {
            if (i >= 2)
                dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]);
            else
                dp[i] = max(dp[i], arr[i] + arr[i-1]);
        }
    }
 
    return dp[N - 1];
}
 
int main()
{
                //3 5 9 10 12 15 17
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr)/sizeof(int); 
    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K);
    return 0;
}