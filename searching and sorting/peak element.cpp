#include <bits/stdc++.h>
using namespace std;
int main(){
	int arr[] = {5, 10, 20, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	int low = 0;
	int high = n - 1;

			// Here sign is of '<' not '<='
	while(low < high){
		int mid = low + (high - low)/2;
		if(arr[mid] > arr[mid + 1])
			high = mid;
		else
			low = mid + 1;
	}
	cout<<arr[low]<<endl;
	return 0;
}