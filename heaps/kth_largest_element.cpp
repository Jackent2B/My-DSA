#include <bits/stdc++.h>
using namespace std;

vector <int> klargest(int arr[], int n, int k){
	
	vector<int> ans;
	priority_queue <int, vector<int>, greater<int>> minh;

	for (int i = 0; i < n; ++i)
	{
		minh.push(arr[i]);
		if(minh.size() > k)
			minh.pop();
	}
	while(minh.size()>0){
		ans.push_back(minh.top());
		minh.pop();
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main(){
	int n = 5;
	int k = 2;
	int arr[] = {12, 5, 787, 1, 23};

	vector <int> v = klargest(arr,n,k);
	for(auto i: v){
		cout<<i<<" ";
	}
	return 0;
}