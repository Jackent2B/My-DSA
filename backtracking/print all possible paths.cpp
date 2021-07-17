#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string s, vector<vector<int>> &vis, int di[], int dj[]){

    if(i==n-1 && j==n-1) {
        ans.push_back(s);
        return; 
    }
    string dir = "DR"; 
    for(int ind = 0; ind<2; ind++) {
        int nexti = i + di[ind]; 
        int nextj = j + dj[ind]; 
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj]){
            vis[i][j] = 1; 
            solve(nexti, nextj, mat, n, ans, s + to_string(mat[nexti][nextj]), vis, di, dj);
            vis[i][j] = 0; 
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat, int n){

    // Visited Array
    vector<vector<int>> vis(n, vector<int>(n,0));
    
    // Vector to store valid paths
    vector<string> ans;

    int di[] = {+1,0};
    int dj[] = {0,+1};
    
    int i = 0;
    int j = 0;
    solve(i,j,mat,n, ans, ""+to_string(mat[i][j]), vis, di, dj); 
    return ans;
}

int main(){
    
    int n;
    cin>>n;
    vector<vector<int>> mat;
    for (int i = 0; i < n; ++i)
    {   
        vector<int> temp;
        for (int j = 0; j < n; ++j)
        {
            int num;
            cin>>num;
            temp.push_back(num);
        }
        mat.push_back(temp);
    }
    vector<string> ans = findPath(mat,n);
    for(int i =0; i<ans.size(); i++)
        cout<<ans[i]<<endl;
    return 0;
}