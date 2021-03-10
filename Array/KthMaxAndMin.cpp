#include <bits/stdc++.h>
using namespace std;

int KthMax(int arr[], int n, int k){
	priority_queue <int, vector<int>, greater<int>> pqm;
	for (int i = 0; i < n; ++i)
	{
		pqm.push(arr[i]);
		if(pqm.size()>k){
			pqm.pop();
		}
	}
	return pqm.top();
}


int KthMin(int arr[], int n, int k){
	priority_queue <int> pqg;
	for (int i = 0; i < n; ++i)
	{
		pqg.push(arr[i]);
		if(pqg.size()>k){
			pqg.pop();
		}
	}
	return pqg.top();
}


int main(){
	int arr[] = { 1000, 11, 445, 
                  1, 330, 3000 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<"Kth max is "<<KthMax(arr,n,k)<<endl;
    cout<<"Kth min is "<<KthMin(arr,n,k)<<endl;
	return 0;
}