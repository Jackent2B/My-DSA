#include <bits/stdc++.h>
using namespace std;

//take floor of the squareroot
int floorSqrt(int x){
	if(x==0)
        return 0;
	int start = 1;
	int end = x;

	int ans;
	while(start<=end){
		int mid = start + (end-start)/2;

		//if(mid*mid == x)   : to avoid integer overflow
		if(mid == x/mid)
			return mid;
		//else if(mid*mid < x){ : to avoid integer overflow
		else if(mid < x/mid){
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