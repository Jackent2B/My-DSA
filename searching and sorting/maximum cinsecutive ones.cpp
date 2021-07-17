#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &nums){
	int ans = 0;
	int count = 0;
	for(int i = 0;i<nums.size(); i++){
		if(nums[i] == 1)
			count++;
		else{
			count = 0;
		}
		ans = max(ans,count);
	}
	return ans;
}

int main(){
	vector <int> nums = {0,1,1,1,0,1,1,1,1};
	cout<<maxConsecutiveOnes(nums);
	return 0;

}