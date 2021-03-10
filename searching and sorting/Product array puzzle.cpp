#include <bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
   
    //code here  
    long long int left[n];
    long long int right[n];
    long long int product_right = 1;
    long long int product_left = 1;
    
    right[n-1] = product_right;
    left[0] = product_left;
     
    for(int  i = n-2 ; i>=0; i--){
        product_right = product_right * arr[i+1];
        right[i] = product_right;
    }
    
    for(int  i = 1 ; i<n; i++){
        product_left = product_left * arr[i-1];
        left[i] = product_left;
    }
    
    vector <long long int> ans;
    for(int i=0; i<n; i++){
        ans.push_back(left[i] * right[i]);
    }
    return ans;
}

int main(){
    vector<long long int> arr;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr.push_back(x);   
    }
    vector <long long int> ans = productExceptSelf(arr,n);
    
    for (int i = 0; i < n; ++i)
        cout<<ans[i]<<" ";

    return 0;
}