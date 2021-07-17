#include <bits/stdc++.h>
using namespace std;

// Top Down Approach
// int coinChange( int arr[], int n, int sum )
// {
   
//     //code here.
//     int dp[n+1][sum+1];
//     for(int i = 0; i<n+1; i++){
//         for(int j = 0; j<sum + 1; j++){
            
//             if(j == 0)
//                 dp[i][j] = 1;
//             else if(j<0 || i == 0)
//                 dp[i][j] = 0;
            
//             else if(arr[i-1]<= j){
//                 dp[i][j] = dp[i][j - arr[i-1]] + dp[i-1][j]; 
//             }
//             else if(arr[i-1]>j){
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     return dp[n][sum];
// }

int t[1001][1001];

int coinChange(int arr[], int n, int sum){

	if(sum==0)
		return 1;
	else if(sum<0 || n == 0)
		return 0;
	else if(t[n][sum] != -1)
		return t[n][sum];
	
	else if(arr[n-1]<= sum){
		return t[n][sum] = coinChange(arr,n,sum-arr[n-1]) + coinChange(arr,n-1,sum);
	}
	else if(arr[n-1]>sum)
		return t[n][sum] = coinChange(arr,n-1,sum);
}

int main(){
	memset(t,-1,sizeof(t));
	int arr[] = {3,5,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 8;
    cout << coinChange(arr, n, sum);
    return 0;
}