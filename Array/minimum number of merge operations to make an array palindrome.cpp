#include <bits/stdc++.h>
using namespace std;

int minimum_merge_operation(int arr[], int n){
	int i =0;
	int j = n-1;
	int count = 0;
	while(i<=j){
		if(arr[i] == arr[j]){
			i++;
			j--;
		}
		else if(arr[i] > arr[j]){
			count++;
			arr[j-1] = arr[j] + arr[j-1];
			j--;
		}
		else{
			count++;
			arr[i+1] = arr[i] + arr[i+1];
			i++;
		}
	}
	return count;
}


int main(){
	int arr[] = {1,4,5,1};
	int n = 4;
	cout<<minimum_merge_operation(arr,n);
	return 0;
}