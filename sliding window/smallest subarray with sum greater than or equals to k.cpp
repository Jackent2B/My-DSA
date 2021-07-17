//dynamic sliding window
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k){
	
	if (n==0)
		return 0;

	int cursum = 0;
	int start = 0;
	int length = INT_MAX;
	for (int end = 0; end < n; end++)
	{
		cursum = cursum + arr[end];

		while(cursum>=k){
			length = min(length, end - start + 1 );
			cursum = cursum - arr[start];
			start++;
		}
	}

	return length;
}

int main()
{
	int arr[] = {4,2,2,7,8,1,2,8,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 8;
	cout<<solve(arr,n,k)<<endl;
	return 0;
}