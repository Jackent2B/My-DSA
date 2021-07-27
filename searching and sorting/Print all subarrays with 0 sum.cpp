#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int count = 0;
    mp[0] = 1;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum = sum + nums[i];  
        if(mp.find(sum-0) != mp.end())
            count=count + mp[sum-0];
        mp[sum]++;
    }
    return count;
}
