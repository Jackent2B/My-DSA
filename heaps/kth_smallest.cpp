#include <bits/stdc++.h>
using namespace std;

int ksmallest(int arr[], int n, int k){
	
	vector<int> ans;
	priority_queue <int> maxh;

	for (int i = 0; i < n; ++i)
	{
		maxh.push(arr[i]);
		if(maxh.size() > k)
			maxh.pop();
	}
	return maxh.top();
}

int main(){
	int n = 6;
	int k = 3;
	int arr[] = {7, 10, 4, 3, 20, 15};

	cout<<ksmallest(arr,n,k);
	return 0;
}