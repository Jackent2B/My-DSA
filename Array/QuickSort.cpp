#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start,int end){
	int pivot = end;
	int partitionIndex = start;
	for (int i = 0; i < end; i++)
	{
		if(arr[i]<pivot){
			swap(arr[i],arr[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(arr[partitionIndex],arr[pivot]);
	return partitionIndex;
}

void QuickSort(int arr[], int start, int end){

	if(start<end){
		int partitionIndex = partition(arr,start,end);
		QuickSort(arr,start,partitionIndex-1);
		QuickSort(arr,partitionIndex+1,end);		
	}

}

int main(){
	int arr[] = {7,6,5,4,2,3,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr,0,n-1);
	
	for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	return 0;
}