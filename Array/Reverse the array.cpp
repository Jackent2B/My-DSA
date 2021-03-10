#include <bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int n){
	int x = n/2;
	int t = 0;
	for(int i = 0; i<x; i++){
		t = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = t;
	}

	for (int i = 0; i < n; ++i)
		cout<<arr[i]<<" ";
}

int main(){
	int arr[] = {1, 2, 3, 4, 5,6};
	int n = sizeof(arr)/sizeof(arr[0]);

	reverse_array(arr,n);
	return 0;
}