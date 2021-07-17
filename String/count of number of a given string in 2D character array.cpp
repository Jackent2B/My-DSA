#include <bits/stdc++.h>
using namespace std;
 
void solve(int i, int j, int m, int n, int &ans, string s, int current_index, vector<vector<int>>& vis, vector<vector<char>>& a, int di[], int dj[]){
    if(current_index == s.length()){
        ans = ans + 1;
        return;
    }

    for(int ind = 0; ind<4;ind++) {
        int nexti = i + di[ind]; 
        int nextj = j + dj[ind]; 
        current_index++;
        if(nexti >= 0 && nextj >= 0 && nexti < m && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] ==s[current_index] ) {
            vis[i][j] = 1; 
            solve(nexti, nextj, m, n, ans, s, current_index, vis,a, di, dj);
            vis[i][j] = 0; 
        }
    }
}
 
// Function to search the string in 2d array
int searchString(string s, vector<vector<char>> &a){
    int ans = 0;
    int m = a.size();
    int n = a[0].size();
    vector<vector<int>> vis(m, vector<int> (n, 0)); 
    int di[] = {+1, 0, 0, -1}; 
    int dj[] = {0, -1, 1, 0};
    // current index of string s to check in a array 
    int current_index = 0;
    for(int i = 0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == s[current_index]) solve(i, j, m, n, ans, s, current_index, vis, a, di, dj); 
        }
    }
    return ans; 
}
 
int main()
{
    string s = "MAGIC";
    vector<vector<char>> a = {  
                               {'B','B','M','B','B','B'},
                                {'C','B','A','B','B','B'},
                                {'I','B','G','B','B','B'},
                                {'G','B','I','B','B','B'},
                                {'A','B','C','B','B','B'},
                                {'M','C','I','G','A','M'}
                            } ;
    cout << "count: " << searchString(s,a) << endl;
    return 0;
}