#include <bits/stdc++.h>
using namespace std;

int min_subarray(int arr[], int n, int k){

	if(n==0)
		return 0;
	
	int min_length = INT_MAX;
	int start = 0;
	int sum  = 0;
	int end;
	for (end = 0; end < n; end++)
	{
		sum = sum + arr[end];
		while(sum > k){
			min_length = min(end - start+1, min_length);
			sum = sum - arr[start];	
			start++;	
		}
	}

	//if we never satisfied the condition: sum>k
	int total = 0;
	for (int i = 0; i < n; ++i)
		total = total + arr[i];
	//if (sum == total) that means we never satisfied: sum>k, hence return 0; 
	if(sum==total)
		return 0;

	return min_length;
};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		int k;
		cin>>k;
		cout<<min_subarray(arr,n,k);
	}
	return 0;
}