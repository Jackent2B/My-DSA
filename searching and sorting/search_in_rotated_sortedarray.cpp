#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int start,int end,int x){

	while(start<=end){
		
		int mid = start + (end-start)/2;	
		if(arr[mid]==x)
			return mid;
		if(arr[mid]<x)
			start = mid+1;
		else 
			end = mid-1;
	}
	return -1;
}

int no_Of_rotations(int arr[],int n){
	if(arr[0]<=arr[n-1])
		return 0;

	int start = 0;
	int end = n-1;
	int pivot = -1;

	while(start<=end){
		if(arr[start]<=arr[end])
			return start;

		int mid = start + (end-start)/2;
		int prev = (mid-1+n)%n;
		int next = (mid+1)%n;

		if(arr[mid]<=arr[prev] && arr[mid]<= arr[next])
		{
			pivot = mid;
			break;
		}
		if(arr[mid]<=arr[end])
			end = mid-1;
		else if(arr[mid]>=arr[start])
			start = start+1;
	}
	return pivot;
}

int main(){
	int arr[] ={4,5,6,7,0,1,2};
	int n = 7;
	int x = 0;
	int rotations = no_Of_rotations(arr,n);

//	first half={4,5,6,7} and second half = {0,1,2}
	cout<<"No. of rotations: "<<rotations<<endl;
	int search_firsthalf =  binary_search(arr,0,rotations-1,x);
	int search_secondhalf = binary_search(arr,rotations,n-1,x);

    cout<<"Answer: ";
	if(search_firsthalf != -1)
		cout<< search_firsthalf;
	else if(search_secondhalf != -1)
		cout<< search_secondhalf;
	else
		cout<<"-1";
	return 0;
}