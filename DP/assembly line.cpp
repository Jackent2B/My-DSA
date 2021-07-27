#include <bits/stdc++.h>
using namespace std;

int carAssembly(vector<vector<int>> &a, vector<vector<int>> &t, int e[], int x[]){

    int m = a.size();
    int n = a[0].size();
    int go[m][n];

    // Initialise last index of both rows
    go[0][n-1] = a[0][n-1] + x[0];
    go[1][n-1] = a[1][n-1] + x[1];

    // Starting from the back till first row
    for(int i = n-2; i>=0; i--){
        go[0][i] = a[0][i] + min(go[0][i+1], t[0][i]+go[1][i+1]);
        go[1][i] = a[1][i] + min(go[1][i+1], t[1][i]+go[0][i+1]);    
    }
    //cout<<go[0][0];
    return min(go[0][0]+e[0], go[1][0] + e[1]);
}

int main()
{
    vector<vector<int>> a = {{4, 5, 3, 2},
                            {2, 10, 1, 4}};
    vector<vector<int>> t = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};
 
    cout << carAssembly(a, t, e, x);
 
    return 0;
}