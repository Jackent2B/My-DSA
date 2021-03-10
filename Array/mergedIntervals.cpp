//gfg

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    //code here
    vector<pair<int,int>> mergedIntervals;
    
    if(n==0)
        return mergedIntervals;
    sort(vec.begin(),vec.end());
    
    pair<int,int> temp = vec[0];
    
    for(auto i:vec){
        if(i.first<=temp.second){
            temp.second = max(i.second,temp.second);
        }else{
            mergedIntervals.push_back(temp);
            temp = i;
        }
    }
    mergedIntervals.push_back(temp);
    return mergedIntervals;
}


//leetcode
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0)
            return mergedIntervals;
        
        sort(intervals.begin(),intervals.end());
        
        vector <int> temp;
        temp = intervals [0];
        
        for(auto i:intervals){
            if(i[0]<= temp[1])
                temp[1] = max(i[1],temp[1]);
            else{
                mergedIntervals.push_back(temp);
                temp = i;
            }
        }
        
        mergedIntervals.push_back(temp);
        return mergedIntervals;
    }
};