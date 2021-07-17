// O(n!) * O(n)
void recurPermutate(int index, vector<vector<int>> &ans,vector<int> &nums){
	if(index == nums.size()){
		ans.push_back(nums);
		return;
	}

	for(int i=index; i<nums.size(); i++){
		swap(nums[index], nums[i]);
		recurPermutate(index+1, nums, ans);
		swap(nums[index], nums[i]);
	}
}

vector<vector<int>> permutate(vector<int> &nums){
	vector<vector<int>> ans;
	recurPermutate(0,ans,nums);
	return ans;
}