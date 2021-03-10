#include <bits/stdc++.h>
using namespace std;

//method 1
int findPair(int arr[], int size, int n){
	int i = 0;
	int j = 0;

    sort(arr,arr+size);

	while(i<size && j<size){
		if(i!=j && arr[j]-arr[i] == n)
			return 1;

		if(arr[j]-arr[i]<n)
			j++;
		else
			i++;

	}
	return -1;
}
//method 2 : using hashset

int main()  
{  
    int arr[] = {1, 8, 30, 40, 100};  
    int size = sizeof(arr)/sizeof(arr[0]);  
    int n = 60;  
    cout<<findPair(arr, size, n);  
    return 0;  
}