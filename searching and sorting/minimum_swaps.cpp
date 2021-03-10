#include <bits/stdc++.h>
using namespace std;

//reference: code library youtube
int minimum_swaps(int arr[], int n){

	vector<pair<int,int>> vec;

	for (int i = 0; i < n; ++i)
	 	vec.push_back(make_pair(arr[i],i)); //or vec[i] = {arr[i],i}

	sort(vec.begin(), vec.end());

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if(i == vec[i].second)
			continue;
		else{
			count++;
			swap(vec[i],vec[vec[i].second]);
			i--;
		}
	}
	return count;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin>>arr[i];

	cout<<minimum_swaps(arr,n);
	return 0;
}