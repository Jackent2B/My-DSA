#include <bits/stdc++.h>
using namespace std;

int smallestSumContiguous(int n, int arr[]){
	
	int minAns = 0;
	int minSoFar = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		minAns = min(minAns + arr[i] ,arr[i]);
		minSoFar = min(minSoFar,minAns);
	}
	return minSoFar;
}

int main(){
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
	cout<<smallestSumContiguous(n,arr);
	return 0;
}