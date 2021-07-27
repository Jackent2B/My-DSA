#include<bits/stdc++.h>
using namespace std;

int xor_operations(int N, int arr[], int M, int K)
{
     
    // If this condition is satisfied,
    // value of M is invalid
    if (M < 0 or M >= N)
        return -1;
     
    // Check if index K is valid
    if (K < 0 or K >= N - M)
        return -1;
     
    // Loop to perform M operations
    for(int p = 0; p < M; p++)
    {
         
        // Creating a temporary list
        vector<int>temp;
     
        // Traversing the array
        for(int i = 0; i < N; i++)
        {
             
            // Calculate XOR values
            // of adjacent elements
            int value = arr[i] ^ arr[i + 1];
             
            // Adding this value to
            // the temporary list
            temp.push_back(value);
             
            // Update the original array
            arr[i] = temp[i];
        }
    }
     
    // Getting value at index K
    int ans = arr[K];
     
    return ans;
}
 
int main()
{
    int N = 5;
    int arr[] = {1, 4, 5, 6, 7};
    int M = 1, K = 2;
     
    cout << xor_operations(N, arr, M, K);
    return 0;
}