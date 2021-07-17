#include <bits/stdc++.h>
using namespace std;

// Reference: Pepcoding sumeet sir
 
int printMaxSubSquare(int R, int C, vector<vector<int>> M)
{
    int dp[R][C];

    int ans = 0;

    for (int i = R-1; i>=0; i--)
    {
        for (int j = C-1; j>=0 ; j--)
        {
            if(i == R-1 && j== C-1){
                dp[i][j] = M[i][j];
            }
            else if(i == R-1){
                dp[i][j] = M[i][j];
            }
            else if(j == C-1){
                dp[i][j] = M[i][j];
            }
            else{
                if(M[i][j] == 0)
                    dp[i][j] = 0;
                else{
                    int t = min(dp[i+1][j],dp[i][j+1]);
                    dp[i][j] = 1+min(t, dp[i+1][j+1]);
                }
            }
        }
    }
    
    for(int i = 0; i<R; i++){
        for(int j=0; j<C; j++){
            ans = max(ans,dp[i][j]);
        }
    }

    return ans;
}


int main()
{
    int R,C;
    cin>>R>>C;

    vector<vector<int>> mat;
    for (int i = 0; i < R; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < C; ++j)
        {
            int num;
            cin>>num;
            temp.push_back(num);
        }
        mat.push_back(temp);
    }
                     
    cout<<printMaxSubSquare(R,C,mat);
}