#include <bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[],int n){

	int cursum = 0;
	int maxsum = INT_MIN;

	for (int i = 0; i < n; ++i)
	{
		cursum = max(cursum + arr[i],arr[i]);
		maxsum = max(maxsum,cursum);
	}
	return maxsum;
}

int main()
{
	int arr[] = {1,2,3,-2,5};
	int n = 5;
	int ans = maxSumSubarray(arr,n);
	cout<<ans<<endl;
	return 0;
}