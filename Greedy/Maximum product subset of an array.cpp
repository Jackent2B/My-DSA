#include <bits/stdc++.h>
using namespace std;

/* Algo: 
1.)If there are even number of negative numbers and no zeros,
    result is simply product of all.
2.) If there are odd number of negative numbers and no zeros,
    result is product of all except the negative integer with the least absolute value.
3.) If there are zeros, result is product of all except these zeros with one exceptional case.
    The exceptional case is when there is one negative number and all other elements are 0.
    In this case, result is 0.
*/

int maxproduct(int arr[], int n){

	int count_zeroes = 0;
	int count_negative = 0;
	int max_neg = INT_MIN;
	int prod = 1;
	for (int i = 0; i < n; ++i)
	{	
		// count zeroes in array
		if(arr[i]==0){
			count_zeroes++;
			// do not include 0 in the product
			continue;
		}

		// count negative numbers in the array
		if(arr[i] < 0){
			count_negative++;
			// find the value of max negative number
			max_neg = max(max_neg,arr[i]);
		}
		prod = prod * arr[i];
	}

	// If all the numbers of array are zero, return 0
	if(count_zeroes == n)
		return 0;

	// if count of negative numbers is odd
	if(count_negative % 2 == 1){
		// if only one is negative number and rest all are zeroes
		if(count_negative == 1 && count_negative + count_zeroes == n)
			return 0;
		else
			prod = prod / max_neg;
	}
	return prod;
}

int main(){
	int arr[] = { -1, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<maxproduct(arr,n);
	return 0;
}