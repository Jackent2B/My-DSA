#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &m,int i, int j, int r, int c){
    if(i >= 0 && j >= 0 && i < r && j < c)
        return true;
    return false;
}

void solve(int i, int j, vector<vector<int>> &a, int r,int c, int &ans, string move, 
    vector<vector<int>> &vis, int di[], int dj[]) {
    if(j==c-1) {
        int l = move.length();
        ans = min(ans,l);
        return; 
    }
    string dir = "DLRU"; 
    for(int ind = 0; ind<4;ind++) {
        int nexti = i + di[ind]; 
        int nextj = j + dj[ind]; 
        if(nexti >= 0 && nextj >= 0 && nexti < r && nextj < c && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
            vis[i][j] = 1; 
            solve(nexti, nextj, a, r,c, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0; 
        }
    }
}

int shortestPath(vector<vector<int>> &m, int r, int c) {
    int ans = INT_MAX;
    vector<vector<int>> vis(r, vector<int> (c, 0)); 
    int di[] = {+1, 0, 0, -1}; 
    int dj[] = {0, -1, 1, 0}; 

    // We can start from any any elemnt from first Col (given in quess)
    for (int i = 0; i < r; ++i)
    {
        if(m[i][0] == 1) solve(i,0,m,r,c, ans, "", vis, di, dj); 
    }
    return ans; 
}

int main(){
    int r,c;
    cin>>r>>c;
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

    int di[] = {+1, 0, 0, -1}; 
    int dj[] = {0, -1, 1, 0}; 
    // Marking land mines and their 4 adjacent cells as -1
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if(m[i][j]==0){
                for (int x = 0; x < 4; ++x)
                {
                    if(isValid(m, i+di[x], j + dj[x], r, c)){
                         m [ i+di[x] ] [ j + dj[x] ] = -1;
                    }
                }
                // if(isValid(m, i, j-1, r, c)){
                //     m[i][j-1] = -1;
                // }
                // if(isValid(m, i+1, j, r, c)){
                //     m[i+1][j] = -1;
                // }
                // if(isValid(m, i, j+1, r, c)){
                //     m[i][j+1] = -1;
                // }
                // if(isValid(m, i-1, j, r, c)){
                //     m[i-1][j] = -1;
                // }
            }
        }
    }

    // We have to avoid land mines and their 4 adjacent cells
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if(m[i][j]==-1){
                m[i][j] = 0;
            }
        }
    }    

    int ans = shortestPath(m,r,c);
    cout<<ans<<endl;
    return 0;
}