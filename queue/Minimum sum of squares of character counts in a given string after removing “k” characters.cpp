#include <bits/stdc++.h>
using namespace std;

int minValue(string s, int k){
        // code here
        priority_queue<pair<int,int>> pq;
        unordered_map<char,int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        
        for(auto i: mp){
            pq.push({i.second , i.first});
        }
        
        while(k--){
            int f = pq.top().first;
            int num = pq.top().second;
            f--;
            pq.pop();
            pq.push({f,num});
            if(pq.top().first==0)
                pq.pop();
        }
        
        int ans = 0;
        while(!pq.empty()){
            int t = pq.top().first;
            ans = ans + (t*t); 
            pq.pop();
        }
        return ans;
}

int main(){
    string s = "abccc";
    int k =1;
    cout<<minValue(s,k);
    return 0;
}