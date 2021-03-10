#include <bits/stdc++.h>
using namespace std;

int getMaxProduct(int arr[], int n){

	int maxAns=arr[0];
	int curMax=arr[0];
	int curMin = arr[0];

	for (int i = 1; i < n; ++i)
	{
		int temp = curMax;
		curMax = max(max(curMax*arr[i],curMin*arr[i]),arr[i]);

		//we are using 'temp' in case the value of curMax gets
		//updated due to above line 
		curMin = min(min(temp*arr[i],curMin*arr[i]),arr[i]);

		maxAns=max(curMax,maxAns);
	}

	return maxAns;
}



int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];

		int ans = getMaxProduct(arr, n);
    	std::cout << ans << std::endl;
	} 
	
	return 0;
}