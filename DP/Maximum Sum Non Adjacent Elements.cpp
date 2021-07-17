#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(vector<int> arr, int n)
{
    int incl[n];
    int excl[n];

    incl[0] = arr[0];
    excl[0] = 0;
       
    for (int i = 1; i < n; ++i)
    {
        incl[i] = excl[i-1] + arr[i];
        excl[i] = max(excl[i-1], incl[i-1]); 
    }

    return max(incl[n-1],excl[n-1]);

}
 
int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int n = arr.size();
    cout<<FindMaxSum(arr, n);
}