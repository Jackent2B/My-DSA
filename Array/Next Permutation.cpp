#include <bits/stdc++.h>
using namespace std;

void next_permutation(int arr[], int n){
	//if n is 1 or 0
	 if(n<=1)
		return;

	//to find first index( say: first_break) which staisfies a[i]<a[i+1]
	int first_break=-1;
	for(int i = n-2; i>=0; i--){
		if(arr[i]<arr[i+1]){
			first_break = i;
			break;
		}
	}
        
    //if we can't find any index which satisfies a[i]<a[i+1] ,
    //then simply reverse the array and return.
    if(first_break<0){
        int p = n/2;
        for (int i = 0; i<p ; i++)
            swap(arr[i],arr[n-1-i]);    
        return;
    }
        

    //find first element from back, which is greater than arr[first_break] element
    //And, then swap them.
	for (int i = n-1; i >first_break; i--)
	{
		if(arr[i]>arr[first_break]){
			swap(arr[i],arr[first_break]);
			break;
		}
	}
       
    //reverse the array after first_break index   
    int x = (n - first_break)/2;
	for (int i = 0; i<x ; i++)
		swap(arr[i+first_break+1],arr[n-1-i]); 

	//reverse STL; reverse(arr + first_break + 1, arr+n)

	//print the array
	for (int i = 0; i < n; ++i)
  		cout<<arr[i]<<" ";     
  	cout<<endl;
}


int main(){
	int arr[] = {1,3,5,4,2}
	int n = 5;
	next_permutation(arr,n);
	return 0;
}