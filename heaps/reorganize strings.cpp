    string reorganizeString(string s) {
        
        // count of characters
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]]++;
        
        // max heap to get the two most occuring elements
        priority_queue<pair<int, char>> maxh;
        
        for(auto it: mp){
            maxh.push({it.second, it.first});
        }
        
        string ans = "";
        while(maxh.size()>1){
            auto t1 = maxh.top();
            auto char1 = t1.second;
            maxh.pop();
            auto t2 = maxh.top();
            auto char2 = t2.second;
            maxh.pop();
            
            ans.push_back(char1);
            ans.push_back(char2);

            t1.first--;
            if(t1.first>0){
                maxh.push(t1);
            }

            t2.first--;
            if(t2.first>0){
                maxh.push(t2);
            }
        
        }
        
        if(!maxh.empty()){
            // checking for the last element 
            // if its count is more than 1
            // then we will surely be having 
            // repeating character so return ""
            if(maxh.top().first>1)
                return "";
            else
                ans.push_back(maxh.top().second);
        }
        return ans;
    }