#include <bits/stdc++.h>
using namespace std;

long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long l,r;
	    sort(arr,arr+n);
	    long long count = 0;
	   for(int i=0;i<n-1;i++){
	        l = i+1;
	        r = n-1;
	       while(l<=r){
	           	if(arr[i]+arr[l]+arr[r] < sum){
		           count = count + (r-l); //it is important
		           l++;
	       		}
	       		else
	           		r--;
	       	}
	   }
	    return count;
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
	    cout<<countTriplets(arr,n,k)<<endl;
	}
	return 0;
}