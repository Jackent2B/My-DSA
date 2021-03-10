#include <bits/stdc++.h>
using namespace std;

void move_all_negative(int arr[], int n){
	int j = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]<0)
		{
   		    if(i!=j)
				swap(arr[i],arr[j]);
		    j++;
		}
	}

	for (int i = 0; i < n; ++i)
		cout<<arr[i]<<" ";
}

int  main(){
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr)/sizeof(arr[0]);
	move_all_negative(arr,n);
	return 0;
}