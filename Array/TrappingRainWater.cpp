#include<iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int totalWater(int arr[], int n){
	int rightArray[n];
	int leftArray[n];

	if(n<=2)
		return 0;

	rightArray[n-1] = arr[n-1];
	for (int i = n-2; i >= 0; i--)
		rightArray[i] =  max(rightArray[i+1],arr[i]);	


	leftArray[0] = arr[0];
	for (int i = 1; i < n; i++)
		leftArray[i] =  max(leftArray[i-1],arr[i]);	

	int result[n];
	for (int i = 0; i < n; i++)
		result[i] = min(rightArray[i],leftArray[i]) - arr[i];

	int ans = result[0];
	for (int i = 1; i < n; ++i)
		ans = ans + result[i];

	return ans;
}


int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<totalWater(arr,n)<<endl;     
	}
	return 0;
}