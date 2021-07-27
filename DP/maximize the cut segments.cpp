#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int find(int len, int x, int y,int z){

    int ans = INT_MIN;
    if(len == 0) return 0;
    if(dp[len] != -1) return dp[len];
    if(len >= x) ans = max(ans,find(len-x,x,y,z)+1);
    if(len >= y) ans = max(ans,find(len-y,x,y,z)+1);
    if(len >= z) ans = max(ans,find(len-z,x,y,z)+1);
    return dp[len] = ans;

}

//Function to find the maximum number of cuts.
int maximizeTheCuts(int n, int x, int y, int z)
{
    memset(dp,-1,sizeof(dp));
    return max(find(n,x,y,z),0);
}