#include <bits/stdc++.h>
using namespace std;

bool largest0sumMatrix(int temp[], int &start, int &end, int r){
    
    unordered_map<int, int> mp;
    int sum = 0; 
    // Initialize length of sub-array with sum 0
    int max_length = 0;
    for (int i = 0; i < r; i++)
    {
        sum = sum + temp[i];
        if (temp[i] == 0 && max_length == 0)
        {
            start = i;
            end = i;
            max_length = 1;
        }
        if (sum == 0)
        {
            if (max_length < i + 1)
            {
                start = 0;
                end = i;
            }
            max_length = i + 1;
        }
 
        if (mp.find(sum) != mp.end())
        {
            int old = max_length;
            max_length = max(max_length, i - mp[sum]);
 
            if (old < max_length)
            {
                // If max_length is updated then
                // enter and update start and end
                // point of array
                end = i;
                start = mp[sum] + 1;
            }
        }
        else
            mp[sum] = i;
    }
    return (max_length != 0);
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

    int temp[r], area, top, bottom;
    for(int left = 0; left < c; left++){
       
        memset(temp, 0, sizeof(temp));
        
        for(int right = left; right < c; right++){
            
            for (int i = 0; i < r; ++i)
                temp[i] += vec[i][right]; // to store values in  temp array
            
            if(largest0sumMatrix(temp, top, bottom, r)){
                area = (right - left) * (bottom-top);
                if(area>maxans){
                    maxans = area;
                    finalLeft = left;
                    finalRight = right;
                    finalTop = top;
                    finalBottom = bottom;
                }    
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
    vector<vector<int>> vec = { { 9, 7, 16, 5 },
                                { 1, -6, -7, 3 },
                                { 1, 8, 7, 9 },
                                { 7, -2, 0, 10 } 
                                };
    cout<<findMaxSum(vec);
    
    return 0;
}
