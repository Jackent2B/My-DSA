#include <bits/stdc++.h>
using namespace std;

//Method 1 O(n*m)log(m), space: O(1)
void merge_without_extraspace(int arr1[], int n, int arr2[], int m){
	int i = 0;
	int j = 0;

	for (int i = 0; i < n; ++i)
	{
		if(arr1[i]<=arr2[j]){
			continue;
		}
		else{
			swap(arr1[i],arr2[j]);
			sort(arr2,arr2+m);
		}
	}

	for (int i = 0; i < n; ++i)
		cout<<arr1[i]<< " ";
	cout<<endl;

	for (int i = 0; i < m; ++i)
		cout<<arr2[i]<<" ";
	cout<<endl;
}

//Method 2 : Gap Method O(n) , Space: O(1)  [based on shell sort]
// void merge_without_extraspace(int arr1[], int n, int arr2[], int m){
	
// 	int length = n+m;

	

// }



int main(){
	int t;
	cin>>t;
	for(int i = 0; i<t; i++){
		int n;
		int m;
		cin>>n;
		cin>>m;
		int arr1[n];
		int arr2[m];

		for(int i = 0; i<n;i++)
			cin>>arr1[i];

		for (int i = 0; i < m; i++)
			cin>>arr2[i];
		merge_without_extraspace(arr1,n,arr2,m);
	}
	return 0;
}