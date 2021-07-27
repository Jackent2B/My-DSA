#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int &start, int &finish, int m){
    int cursum = 0, maxSum = INT_MIN;
    int i;
    finish = -1;
 
    int local_start = 0;
 
    for (i = 0; i < m; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            start = local_start;
            finish = i;
        }
    }
 
    if (finish != -1)
        return maxSum;
 
 
    // Special Case: When all numbers
    // in arr[] are negative
    maxSum = arr[0];
    start = finish = 0;
 
    for (i = 1; i < m; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            start =  finish = i;
        }
    }
    return maxSum;
}
 
int findMaxSum(vector<vector<int>> &M)
{
    int ROW = M.size();
    int COL = M[0].size();
    int maxSum = INT_MIN;

    int finalLeft,finalRight,finalTop,finalBottom;
 
    int left, right, i;
    int temp[ROW], sum, start, finish;
 
    // Set the left column
    for (left = 0; left < COL; ++left) {
        memset(temp, 0, sizeof(temp));
 
        for (right = left; right < COL; ++right) {
 
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];
 

            sum = kadane(temp, start, finish, ROW);
             if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
    return maxSum;    
}

int main()
{
    vector<vector<int>> vec = { { 1, 2, -1, -4, -20 },
                                { -8, -3, 4, 2, 1 },
                                { 3, 8, 10, 1, 3 },
                                { -4, -1, 1, 7, -6 } };
 
    cout<<findMaxSum(vec);
    return 0;
}
