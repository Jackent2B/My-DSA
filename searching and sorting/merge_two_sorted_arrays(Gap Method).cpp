#include <bits/stdc++.h>
using namespace std;

//Method 1 O(n)log(n), space: O(1)
void merge_without_extraspace(int arr1[], int n, int arr2[], int m){

	int total = n+m;
	int x = (total%2==0?total/2:(total/2+1));


}

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