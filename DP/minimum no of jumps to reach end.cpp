#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int N){
    
    if(arr[0] == 0 || N==0)
        return -1;
        
    int dp[N];
	dp[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		dp[i] = INT_MAX;
		for (int j = 0; j < i; ++j)
		{
			if(arr[j] + j >=i && dp[j] != INT_MAX){
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}
	
	if(dp[N-1] != INT_MAX)
	    return dp[N-1];
	else    
	    return -1; 
}

int main(){ 	
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int N = 11;
	minJumps(arr,N);
	return 0;
}
