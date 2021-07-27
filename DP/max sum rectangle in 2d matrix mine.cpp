#include <bits/stdc++.h>
using namespace std;

// Easy and conceptual and IMP

int kadane(int arr[], int &start, int &end, int r){
    // we are writing this much of code in kadane because we need to find the
    // starting index and ending index of the max sum contiguous subarray as well

    int cursum = 0;
    int maxsum = INT_MIN;
    int startlocal = 0; // it will give the possible value of starting index
    int i; // it will give the possible value of final index
    end = -1;

    for(i=0; i<r; i++){
        cursum = cursum + arr[i];
        if(cursum<0){
            cursum = 0;
            startlocal = i+1;
        }else if(cursum > maxsum){
            maxsum = cursum;
            start = startlocal;
            end = i;
        }
    }

    if(end != -1)
        return maxsum;

    // if all elements are negative
    maxsum = arr[0];
    start = 0;
    end = 0;
    for(int i = 1; i<r; i++){
        if (arr[i] > maxsum){
            maxsum = arr[i];
            start = i;
            end = i;
        }
    }
    return maxsum;
}
 
int findMaxSum(vector<vector<int>> &vec)
{
    int r = vec.size();
    int c = vec[0].size();

    int maxans = INT_MIN;
    int finalLeft = 0;
    int finalRight = 0;
    int finalTop = 0;
    int finalBottom = 0;

    int temp[r], sum, top, bottom;
    for(int left = 0; left < c; left++){
       
        memset(temp, 0, sizeof(temp));
        
        for(int right = left; right < c; right++){
            
            for (int i = 0; i < r; ++i)
                temp[i] += vec[i][right]; // to store values in  temp array
            
            sum = kadane(temp, top, bottom, r);
            if(sum>maxans){
                maxans = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = top;
                finalBottom = bottom;
            }

        }
    }
    
    // To print the submatrix
    for(int i = finalTop; i<=finalBottom; i++){
        for(int j = finalLeft; j<= finalRight; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    return maxans;
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
