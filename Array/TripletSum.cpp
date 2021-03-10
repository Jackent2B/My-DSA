#include <bits/stdc++.h>
using namespace std;

bool tripletSum (int arr[], int n, int k){
		
	int l,r;

	sort(arr,arr+n);

	for (int i = 0; i < n-2; i++)
	{
		l=i+1;
		r=n-1;
		while(l<r){
			if(arr[i]+arr[l]+arr[r] == k){
				return 1;
			}
			else if(arr[i]+arr[l]+arr[r] < k){
				l++;
			}
			else if(arr[i]+arr[l]+arr[r] > k){
				r--;
			}
		}
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n;
	    cin>>k;
	    int arr[n]; // 1 4 4 5 6 8 10
	    for(int i=0; i<n; i++)
	        cin>>arr[i];
	    cout<<tripletSum(arr,n,k)<<endl;
	}
	return 0;
}