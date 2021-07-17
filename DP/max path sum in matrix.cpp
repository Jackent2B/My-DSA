#include <bits/stdc++.h>
using namespace std;

// Based on GoldMine Problem
int maximumPath(int N, vector<vector<int>> Matrix)
{
        // code here
        int dp[N][N];
        memset(dp, 0, sizeof(dp));
        
        for(int i = N-1; i>=0; i--){
            for(int j = 0; j<N; j++){
                int left_down = (i == N-1 || j==0)? 0: dp[i+1][j-1];
                int down = (i == N-1)?0:dp[i+1][j];
                int right_down = (i == N-1 || j==N-1)? 0: dp[i+1][j+1];
                
                dp[i][j] = Matrix[i][j] + max(max(left_down,right_down),down);
            }
        }
        int res = dp[0][0];
        for (int i=1; i<N; i++)
            res = max(res, dp[0][i]);
        return res;
}