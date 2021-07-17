#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue <long long int, vector<long long int>, greater<long long int>> minh(arr,arr+n);
    
    // for(int i=0; i<n; i++){
    //     minh.push(arr[i]);
    // }
    long long int ans = 0;
    while(minh.size()>1){
        long long int top = minh.top();
        minh.pop();
        long long int second_top = minh.top();
        minh.pop();
        ans = ans + top + second_top;
        minh.push(top + second_top);
    }
    return ans;
}

int main(){
    int arr = {4,2,3,6};
    int n = 4;
    cout<<minCost(arr,n);
    return 0;
}