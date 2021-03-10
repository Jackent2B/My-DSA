#include <bits/stdc++.h>
using namespace std;

//method1: Two For loop (naive's method)
// int count1(int arr[], int n, int k){
// }

//method2: using hashmaps
int count2(int arr[], int n, int k){
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++)
        m[arr[i]]++;

    int count = 0;
	for (int i = 0; i < n; ++i)
	{
	 	//if(m.find(k-arr[i]) != m.end())
	 	count = count + m[k-arr[i]];
	 
	 	//so that (arr[i],arr[i]) pair is not considered
	 	if(k-arr[i] == arr[i])
	 		count--;
	}
	return count/2; //because each pair is counted twice
}

//method 3: sorting
// int count3(int arr[], int n, int k){
	
// 	sort(arr,arr+n);

// 	int l = 0;
// 	r = n-1;
// 	while(l<r){
// 		if(arr[l] + arr[r] > k)
// 			r--;
// 		else if(arr[l] + arr[r] < k)
// 			l++;
// 		else{
// 			count++;
// 			l++;
// 		}
// 	}
// 	return count;
// }



int main(){
 	int arr[] = {1, 5, 7, 1,3,3};
 	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 6;
	cout<<count2(arr,n,k);
	return 0;
}