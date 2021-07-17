//fixed size sliding window
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int k){
	
	if(n==0)
		return 0;

	int cursum = 0;
	int maxsum = INT_MIN;

	int start = 0;
	int end = 0;

	while(end<n){
		
		cursum  = cursum + arr[end];

		if(end-start+1<k){
			end++;
		}
		else if(end - start + 1 == k){
			maxsum = max(maxsum, cursum);
			cursum = cursum - arr[start];
			start++;
			end++;
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
