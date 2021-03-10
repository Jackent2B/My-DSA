#include <bits/stdc++.h>
using namespace std;

int largest_no_in_rotated_sorted_array(int arr[], int n){
    if(arr[0] < arr[n-1]){
		return arr[n-1];
	}
	int pivot = -1;
	int s = 0, e = n-1;
	while(s <= e){
		//this if condition is very important
        if(arr[s] <= arr[e]){
            return arr[e];
        }
		int mid = s + (e-s)/2;
		int next = (mid+1)%n;
		int prev = (mid-1+n)%n;
		if(arr[mid] >= arr[next] && arr[mid] >= arr[prev]){
            pivot = arr[mid];
		    break;
		}
		if(arr[s] <= arr[mid]){
		    s = mid + 1;
		}
		else if(arr[mid] <= arr[e]){
			e = mid - 1;
		}
	}
	return pivot;
}

int main(){
	int arr[] ={4,5,6,7,8,0,1,2};
	int n = 7;
	int ans = largest_no_in_rotated_sorted_array(arr,n);
	cout<<ans<<endl;
	return 0;
}