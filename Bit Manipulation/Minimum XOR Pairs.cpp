#include <bits/stdc++.h>
using namespace std;

// Note: you vae to do it in O(nlogn)
int minimumXOROfPair(vector<int>& arr) {
    
    int minans = INT_MAX;
    // sort the array
    sort(arr.begin(),arr.end());
    for (int i = 0; i < arr.size()-1; ++i)
        minans = min(minans,arr[i]^arr[i+1]);
    return minans;
}
    

int main(){
    vector<int> arr = {1 , 5, 9, 6, 8};
    cout<<minimumXOROfPair(arr);
    return 0;
}