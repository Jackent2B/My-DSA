
#include <bits/stdc++.h>
using namespace std;
 
int MaxSumDifference(int arr[], int n)
{
	sort(arr, arr+n);

	int i = 0;
	int j = n-1;
	vector<int> v;
	while(i<=j){
	    if(i==j){
            v.push_back(arr[i]);
	        i++;
		    j--;
		    continue;
	    }
		v.push_back(arr[i]);
		v.push_back(arr[j]);
		i++;
		j--;
	}
	for(auto it: v)
	    cout<<it<<" ";
	int ans = 0;
	for(int i = 0; i<n-1; i++){
		ans = ans + abs(v[i] - v[i+1]);
	}

	ans = ans + abs(v[n-1] - v[0]);
	return ans;
}
 
int main()
{
    int a[] = { 1, 2, 4, 8,5 };
    int n = sizeof(a) / sizeof(a[0]);
 
    cout << MaxSumDifference(a, n) << endl;
}