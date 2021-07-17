#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n){

	int count = 0;
	for(int i=0; i<=n-2; i++){

		if(max(arr[i],arr[i+1])/min(arr[i],arr[i+1]) >2){
	        
	        //no. of insertions to be made
	        int no_of_insertions = log2(max(arr[i],arr[i+1])/min(arr[i],arr[i+1]));
	        
	        // cout<<floor(no_of_insertions)<<" ";
	        count = count + no_of_insertions;	
	        // if(floor(no_of_insertions) == no_of_insertions){
	        // 	count = count + no_of_insertions;	
	        // }
	        // else{
	        // 	count = count + floor(no_of_insertions)-1;	
	        // }
		}
	}
	return count;
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

		cout<<solve(arr,n)<<endl;
	}
	return 0;
}