#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m){
	if(n<m)
		return -1;

	sort(arr,arr+n);
	int min_diff = INT_MAX;
					
					//arr[i] is first element of the m sized sorted window and
					// arr[i+m-1] is the last. 
	for (int i=0; i+m-1<n; i++) 
    {
        int diff = arr[i+m-1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main()
{
    int arr[] = {3, 4, 1 ,9, 56, 7 ,9 ,12}; //sorted:1 3 4 7 9 9 12 56
    int m = 5;  // Number of students
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMinDiff(arr, n, m);
    return 0;
}