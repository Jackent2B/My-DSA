#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
vector<int> grp1final;
vector<int> grp2final;

void tugOfWar(int arr[],int idx, int n, vector<int> &grp1, vector<int> &grp2, int grp1sum, int grp2sum){
	if(idx == n){
		int diff = abs(grp1sum - grp2sum);
		if(diff < ans){
		    ans = diff;
            grp1final = grp1;
            grp2final = grp2;
		}
		return;
	}

	// each element will have two choices, whether to go in grp1 or 
	// whether to go in grp2

	// it an element is going to be part of grp 1
	if(grp1.size()<(n+1)/2){
		grp1.push_back(arr[idx]);
		tugOfWar(arr, idx+1, n, grp1, grp2, grp1sum + arr[idx], grp2sum);
		grp1.pop_back();
	}

	// if an element is going to be part of grp 2
	if(grp2.size()<(n+1)/2){
		grp2.push_back(arr[idx]);
		tugOfWar(arr, idx+1, n, grp1, grp2, grp1sum, grp2sum + arr[idx]);
		grp2.pop_back();
	}
	return;
}

int main(){
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> grp1;
	vector<int> grp2;
	int grp1sum = 0;
	int grp2sum = 0;
	tugOfWar(arr, 0, n, grp1, grp2, grp1sum, grp2sum);

	// Printing the ans;
	cout<<ans<<endl;
	for(int i=0; i<grp1final.size(); i++)
	    cout<<grp1final[i]<<" ";
	cout<<endl;
	for(int i=0; i<grp2final.size(); i++)
	    cout<<grp2final[i]<<" ";
    return 0;
}