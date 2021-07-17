#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &a, int r,int c, int &ans, string move, 
    vector<vector<int>> &vis, int di[], int dj[], int x, int y) {
    if(i==x && j==y) {
        int l = move.length();
        ans = max(ans,l);
        return; 
    }
    string dir = "DLRU"; 
    for(int ind = 0; ind<4;ind++) {
        int nexti = i + di[ind]; 
        int nextj = j + dj[ind]; 
        if(nexti >= 0 && nextj >= 0 && nexti < r && nextj < c && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
            vis[i][j] = 1; 
            solve(nexti, nextj, a, r,c, ans, move + dir[ind], vis, di, dj, x, y);
            vis[i][j] = 0; 
        }
    }
}

int longestPath(vector<vector<int>> &m, int r, int c, int x, int y) {
    int ans = INT_MIN;
    vector<vector<int>> vis(r, vector<int> (c, 0)); 
    int di[] = {+1, 0, 0, -1}; 
    int dj[] = {0, -1, 1, 0}; 
    if(m[0][0] == 1) solve(0,0,m,r,c, ans, "", vis, di, dj,x,y); 
    return ans; 
}
int main(){
    int r,c;
    cin>>r>>c;

    // Destination
    int x,y;
    cin>>x>>y;

    vector<vector<int>> m;
    for (int i = 0; i < r; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < c; ++j)
        {
            int num;
            cin>>num;
            temp.push_back(num);
        }
        m.push_back(temp);
    }
    int ans = longestPath(m,r,c,x,y);
    cout<<ans<<endl;
    return 0;
}