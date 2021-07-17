#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];

bool EqualSumSubset(int arr[], int n, int s){

	if(n == 0)
		return 0;
	else if(s == 0)
		return 1;
	else if(t[n][s] != -1)
		return t[n][s];
	else if(arr[n-1]>s){
		return t[n][s] =  EqualSumSubset(arr,n-1,s);
	}
	else if(arr[n-1]<=s){
		return t[n][s]= EqualSumSubset(arr,n-1,s - arr[n-1]) || EqualSumSubset(arr,n-1,s) ;
	}
}

int main(){

	memset(t , -1, sizeof(t));
	int arr[] = {1,5,11,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum = sum + arr[i];

	if(sum%2 != 0)
		cout<<"No";
	else{
		if(EqualSumSubset(arr,n,sum/2))
		    cout<<"Yes";
		else
		    cout<<"No"
	}

	return 0;
}