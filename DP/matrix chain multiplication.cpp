#include <bits/stdc++.h>
using namespace std;

int t[101][101];

int mcm(int arr[], int i, int j){
	
	if(i>=j)
		return 0;

	int mn = INT_MAX;

	if(t[i][j] != -1)
		return t[i][j];

	for (int k = i; k <= j-1; k++)
	{
		int ans = mcm(arr,i,k) + mcm(arr,k+1,j) + (arr[i-1] * arr[k] * arr[j]);
		mn = min(ans,mn);
	}
	return t[i][j] = mn;
}

int main(){
	memset(t, -1, sizeof(t));
	int arr[] = {40,20,30,10,30};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<mcm(arr,1,n-1);
	return 0;
}