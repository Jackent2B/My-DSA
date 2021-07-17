#include<iostream> 
using namespace std; 

int findMissingUtil(int arr[], int low, int high, int diff) 
{ 
    // There must be two elements to find the missing 
    if (high <= low) 
        return INT_MAX; 
  
    int mid = low + (high - low) / 2; 
  
    if (arr[mid + 1] - arr[mid] != diff) 
        return (arr[mid] + diff); 
  
    if (mid > 0 && arr[mid] - arr[mid - 1] != diff) 
        return (arr[mid - 1] + diff); 
  
    // If the elements till mid follow AP, then recur for right half 
    //an = a1 + (n-1)*d  : nth term of AP
    if (arr[mid] == arr[0] + mid * diff) 
        return findMissingUtil(arr, mid + 1,  
                               high, diff); 
  
    // Else recur for left half 
    return findMissingUtil(arr, low, mid - 1, diff); 
} 
 
int findMissing(int arr[], int n)  
{ 

    int diff = (arr[n - 1] - arr[0]) / n; 
    return findMissingUtil(arr, 0, n - 1, diff); 
} 
 
  
// Driver Code 
int main() 
{ 
    int arr[] = {2, 4, 8, 10, 12, 14}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout <<  findMissing(arr, n); 
    return 0; 
}  