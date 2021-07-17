#include <bits/stdc++.h>
using namespace std;

int kadane(int n, int arr[]){
	
	int maxAns = 0;
	int maxSoFar = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		maxAns = max(maxAns + arr[i] ,arr[i]);
		maxSoFar = max(maxSoFar,maxAns);
	}
	return maxSoFar;
}

int main(){
	int n =5;
	int arr[] ={1,2,3,-2,5};
	cout<<kadane(n,arr);
	return 0;
}