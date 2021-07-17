// Leetcode solution in discussion portal
#include <bits/stdc++.h>
using namespace std;
 
// This returns count of elements in matrix less than of equal to num
int getElementsGreaterThanOrEqual(int val, int n, int mat[4][4]) {
    int res =0;
    int i = n - 1, j = 0;
    // Very Nice concept
    while (i >= 0 && j < n) {
        if (mat[i][j] > val) i--;
        else {
            res += i + 1;
            j++;
        }
    }
    return res;
}
 
int kthSmallest(int mat[4][4], int n, int k) {
    //  We know the answer lies between the first and the last element
    // So do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = mat[0][0], r = mat[n - 1][n - 1];
 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);
 
        if (greaterThanOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
 
int main() {
    int n = 4;
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };
    int k = 7;
    cout << kthSmallest(mat, n, k);
    return 0;
}