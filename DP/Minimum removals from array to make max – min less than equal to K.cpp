#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
 
// function to check all possible combinations
// of removal and return the minimum one
int countRemovals(int a[], int i, int j, int k)
{
    // base case when all elements are removed
    if (i >= j)
        return 0;
 
    // if condition is satisfied, no more
    // removals are required
    else if ((a[j] - a[i]) <= k)
        return 0;
 
    // if the state has already been visited
    else if (dp[i][j] != -1)
        return dp[i][j];
 
    // when Amax-Amin>d
    else if ((a[j] - a[i]) > k) {
 
        // minimum is taken of the removal
        // of minimum element or removal
        // of the maximum element
        return dp[i][j] = 1 + min(countRemovals(a, i + 1, j, k),
                           countRemovals(a, i, j - 1, k));
    }
}
 

int removals(int a[], int n, int k)
{
    // sort the array
    sort(a, a + n);
 
    memset(dp, -1, sizeof(dp));
    if (n == 1)
        return 0;
    else
        return countRemovals(a, 0, n - 1, k);
}
 
int main()
{
    int a[] = { 1, 3, 4, 9, 10, 11, 12, 17, 20 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    cout << removals(a, n, k);
    return 0;
}