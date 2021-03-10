#include <bits/stdc++.h>
using namespace std; 
   
int minSwap(int arr[], int n, int k) { 
  
    //count the no. of elements less than k
  	int count = 0;
    for (int i = 0; i < n; ++i)
    {
    	if(arr[i]<=k)
    		count++;
    }

    int bad = 0;
    for (int i = 0; i < count; ++i)
    {
    	if(arr[i]>k)
    		bad++;
    }

//different type of sliding window
    int ans = INT_MAX;
    int i=0;
    int j = count -1;
    while(j<n){
    	ans = min(ans,bad);
    	j++;
    	if(j<n && arr[j]>k)
    		bad++;
    	if(arr[i]>k)
    		bad--;
    	i++;	
    }
    return ans;
} 

int main() { 
      
    int arr[] = {2, 1, 5, 6, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    cout << minSwap(arr, n, k) << "\n"; 
    return 0; 
} 