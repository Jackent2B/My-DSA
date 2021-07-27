#include <bits/stdc++.h>
using namespace std;

// Note: you vae to do it in O(n)
int getXORSum(vector<int>& arr) {
    int xorsum = 0;
    for(int i=0; i<arr.size(); i++){
        xorsum = xorsum ^ 2*arr[i];
    }
    return xorsum;
}
    

int main(){
    vector<int> arr = {1 , 5, 7, 8};
    cout<<getXORSum(arr);
    return 0;
}