/*Algo:The idea is based on the fact that if an max element till 'i' is
 equal to index 'i',then we can make a partition ending with i.  
*/
#include <bits/stdc++.h>
using namespace std;
 
// Function to find maximum partitions.
int maxPartitions(int arr[], int n)
{
    int ans = 0, max_so_far = 0;
    for (int i = 0; i < n; ++i) {
 
        // Find maximum in prefix arr[0..i]
        max_so_far = max(max_so_far, arr[i]);
 
        // If maximum so far is equal to index,
        // we can make a new partition ending at
        // index i.
        if (max_so_far == i)
            ans++;
    }
    return ans;
}
 
int main()
{
    int arr[] = { 1, 0, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxPartitions(arr, n);
    return 0;
}