#include <bits/stdc++.h>
using namespace std;

struct Pair 
{
    int min;
    int max;
};

struct Pair getMaxMin(int arr[], int first, int last){
	
	struct Pair minmax, left, right; 
	
	minmax.max = INT_MIN;
	minmax.min = INT_MAX;
	//if arrays has only one element
	if(first == last){
        minmax.max = arr[first];
        minmax.min = arr[first];     
        return minmax;
	}

	//if array has only two elements
	if(first+1==last){
		 if (arr[first] > arr[last]) 
        {
            minmax.max = arr[first];
            minmax.min = arr[last];
        } 
        else
        {
            minmax.max = arr[last];
            minmax.min = arr[first];
        } 
		return minmax;
	}

	int mid = first + (last-first)/2;

	left = getMaxMin(arr,first,mid);
	right = getMaxMin(arr, mid + 1 , last);

	if(minmax.max < max(left.max, right.max))
		minmax.max = max(left.max, right.max);
	
	if(minmax.min > min(left.min, right.min))
		minmax.min = min(left.min, right.min);
	

	return minmax;
}


int main(){

	int arr[] = { 1000, 11, 445, 1, 330, 3000 }; 
	int n = sizeof(arr)/sizeof(arr[0]);

	struct Pair ans= getMaxMin(arr,0,n-1);
	
	cout<<"Max element is "<<ans.max<<endl;
	cout<<"Min element is "<<ans.min<<endl;	

	return 0;
}