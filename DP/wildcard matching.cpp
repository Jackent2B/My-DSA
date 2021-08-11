class Solution {
public:
    int dp[20001][20001];
    bool solve(string s, string p, int m, int n){
        if(m==0 && n==0){
            return true;
        }
        // If string is completed but pattern is not
        else if(m==0){
            // it all the characters which are left in string p are '*' then return true
            // else return false;
            for(int i = 0; i<n; i++){
                if(p[i]!='*')
                    return false;
            }
            return true;
        }
        // if pattern is completed but string is not
        else if(n==0)
            return false;
        else if(dp[n][m] != -1)
            return dp[n][m];
        else{
            if(s[m-1]==p[n-1] || p[n-1]=='?')
                return dp[n][m] = solve(s,p,n-1,m-1);
            else if(p[n-1]=='*'){
                return dp[n][m]=solve(s,p,m,n-1) || solve(s,p,m,n-1); 
            }
        }
    return 0;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,p,m,n);
    }
};