#include <bits/stdc++.h>
using namespace std;

//Method 1
// int find_duplicate(int arr[], int n){
//     sort(arr,arr+n);
//     int ans = 0;
//     for(int i=0 ; i<n-1; i++){
//         if(arr[i] == arr[i+1])
//            ans= arr[i];
//     }
//     return ans;
// }


//Method 2 : using linked-list cycle (Best Method) (O(n) O(1)space)
int find_duplicate(int arr[], int n){ 
    int slow=arr[0],fast=arr[0];
    while(true)
    {
        slow=arr[slow];
        fast=arr[arr[fast]];
        if(slow==fast)
            break;
    }
    slow=A[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;

}

int main(){
	int arr[]={1,3,4,2,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<find_duplicate(arr,n);
	return 0;
}