#include <bits/stdc++.h>
using namespace std;
#define N 4
rotate90Clockwise(vector<vector<int>> &arr)
{
    int N = arr.size();
    //Transpose of a matrix
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++)
            swap(arr[i][j], arr[j][i]);
    }

    //Reverse each row
    for(int i=0; i<N; i++){
        reverse(arr[i].begin(),arr[i].end());
    }
}
int main()
{
    vector<vector<int>> arr = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    return 0;
}
