#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n){
   
    int count = 0; 
    while(n){
        n = n & n-1;
        count++;
    }
    return count;
} 

void sortBySetBitCount(int arr[], int n){
    // map to order in descending order
    map<int ,vector<int>, greater <int>> mp;
    for(int i=0; i<n; i++){
        int setbitsOf_i = countSetBits(arr[i]);
        mp[setbitsOf_i].push_back(arr[i]);
    }

    for(auto itr: mp){
        for(auto c : itr.second)
        {
            cout << c << " ";
        }
    }
    return;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortBySetBitCount(arr, n);
}