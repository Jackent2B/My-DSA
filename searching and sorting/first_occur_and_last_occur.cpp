#include <iostream>
using namespace std;

int first_occurence(int arr[], int n, int x){
    
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
           int mid = start + (end-start)/2;
        if(arr[mid]<x)
            start = mid +1;
        else if(arr[mid]>x)
            end = mid-1;
        else{
            ans = mid;
            end = mid-1;
        }
    }
    
    return ans;
}


int last_occurence(int arr[], int n, int x){
    
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]<x)
            start = mid +1;
        else if(arr[mid]>x)
            end = mid-1;
        else{
            ans = mid;
            start = start+1;
        }
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0; i<n;i++)
            cin>>arr[i];
    
        int firstAns = first_occurence(arr,n,x);
        int lastAns = last_occurence(arr,n,x);
        
        if(firstAns == -1 || lastAns == -1)
            cout<<"-1"<<endl;
        else        
            cout<<firstAns<<" "<<lastAns<<endl;
    }
    return 0;
}