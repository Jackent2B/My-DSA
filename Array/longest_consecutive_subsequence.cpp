#include <bits/stdc++.h>
using namespace std;

int longest_consecutive_subsequence(int arr[], int n){
	
	unordered_set<int> set;
	
	int maxcount = 0;

	for (int i = 0; i < n; ++i)
		set.insert(arr[i]);

	for (int i = 0; i < n; ++i)
	{
		if(set.find(arr[i]-1) == set.end()){
			int x = arr[i];

			while(set.find(x) != set.end()){
				x++;
			}

			maxcount = max(maxcount,x-arr[i]);
		}
	}
	return maxcount;
}

int main(){
	int arr[] = { 1, 9, 3, 10, 4, 20, 2 }; 
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<longest_consecutive_subsequence(arr,n);
	return 0;
}