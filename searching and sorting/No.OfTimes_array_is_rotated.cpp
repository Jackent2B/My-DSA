#include <bits/stdc++.h>
using namespace std;

int no_Of_rotations(int arr[], int n){
    if(arr[0] < arr[n-1]){
		return 0;
	}
	int pivot = -1;
	int s = 0, e = n-1;
	while(s <= e){
		//this if condition is very important
        if(arr[s] <= arr[e]){
            return s;
        }
		int mid = s + (e-s)/2;
		int next = (mid+1)%n;
		int prev = (mid-1+n)%n;
		if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
            pivot = mid;
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
	int arr[] ={4,5,6,7,0,1,2};
	int n = 7;
	int ans = no_Of_rotations(arr,n);
	cout<<ans<<endl;
	return 0;
}