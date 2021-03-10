#include <bits/stdc++.h>
using namespace std;

bool binary_search(vector<int> sorted_arr, int target){
	int n = sorted_arr.size();
	int start = 0;
	int end = n-1;
	while(start<=end){
		int mid = (start+end)/2;
		if (target==sorted_arr[mid])
			return true;
		else if(target<sorted_arr[mid])
			end = mid-1;
		else if(target>sorted_arr[mid])
			start = mid+1;
	}
	return false;
}
    
bool searchMatrix(vector<vector<int>>& vec, int target){
    vector<int> sortedArr;
	int R = vec.size();
	int C = vec[0].size();
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			sortedArr.push_back(vec[i][j]);
		}
	}
	return binary_search(sortedArr,target);
}

int main(){
	int R = 3;
	int C = 4;  
	vector<vector<int>> vec;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin>>vec[i][j];
		}
	}
	int target;
	cin>>target;
	if(Searchtarget(vec,target))
		cout<<"true";
	else
		cout<<"false";
	return 0;
}