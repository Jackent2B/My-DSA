#include <bits/stdc++.h>
using namespace std;

//logic
int solve(int trees, int heights[], int required_wood, int mid){
	
	int wood_received = 0;
	for (int i = 0; i < trees; ++i)
	{
		if(heights[i] > mid)
			wood_received = wood_received + (heights[i] - mid);
		if(wood_received>=required_wood)
			return 1; 
	}
	return 0;
}

int main(){
	int trees;
	cin>>trees;

	int required_wood;
	cin>>required_wood;

	int heights[trees];
	for (int i = 0; i < trees; ++i)
		cin>>heights[i];

	int start = 0;
	int end = *max_element(heights, heights + trees); //max element of an array
	int ans;

	//binary search
	while(start<=end){
		int mid = start + (end-start)/2;
		if(solve(trees,heights,required_wood,mid)){
			ans = mid;
			start = mid + 1; //increase the height to get the most optimize answer
		}
		else
			end = mid - 1;
	}
	cout<<ans;
}