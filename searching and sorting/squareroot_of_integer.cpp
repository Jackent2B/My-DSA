#include <bits/stdc++.h>
using namespace std;

//take floor of the squareroot
int floorSqrt(int x){
	int start = 0;
	int end = x;

	int ans;
	while(start<=end){
		int mid = start + (end-start)/2;

		if(mid*mid == x)
			return mid;
		else if(mid*mid < x){
			ans = mid; //because it can be a possible answer as we have to take the floor
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
	return ans;
}

int main(){
	int x = 12; 
    cout << floorSqrt(x) << endl; 
	return 0;
}