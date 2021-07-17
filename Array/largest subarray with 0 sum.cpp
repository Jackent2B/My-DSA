#include <bits/stdc++.h>
using namespace std;

int largestSubarrayZeroSum(int arr[], int n){
	int ans = 0;
	int sum = 0;

	unordered_map<int , int> mp;
	for (int i = 0; i < n; ++i)
	{
		sum = sum + arr[i];
		if(sum == 0){
			ans = i+1;
		}
		else{
			if(mp.find(sum) != mp.end()){
				ans = max(ans, i - mp[sum]);
			}
			else{
				mp[sum] = i;
			}
		}
	}
	return ans;
}

int main(){
	int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<largestSubarrayZeroSum(arr,n);
	return 0;
}