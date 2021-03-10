#include <bits/stdc++.h>
using namespace std;

bool subArrayEqualZeroSum(int arr[], int n){
	unordered_set<int> s;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum+arr[i];
		if(sum == 0 || s.find(sum) != s.end() )
			return 1;

		s.insert(sum);
	}
	return 0;
}

int main(){
	int arr[] = {4, 2, 0, 1, 6};
	int n = sizeof(arr)/sizeof(arr[n]);
	if(subArrayEqualZeroSum(arr,n))
		cout<<"yes"<<endl;
	else
		cout<<"yes"<<endl;
	return 0;
}