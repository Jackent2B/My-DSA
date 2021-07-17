//fixed size sliding window
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k){
	
	if(n==0)
		return 0;

	int cursum = 0;
	int maxsum = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		cursum = cursum + arr[i];
		if(i >= k-1){
			maxsum = min(maxsum,cursum);
			cursum = cursum - arr[i - (k-1)];
		}
	}
	return maxsum;
}

int main(){
	int arr[] = {4,-3,2,8,-1,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout<<solve(arr,n,k)<<endl;
	return 0;
}
