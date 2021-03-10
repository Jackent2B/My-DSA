#include <bits/stdc++.h>
using namespace std;

//refer: aditya vermas
struct Pair{
	int missing;
	int repeating;
};

struct Pair missingAndRepeating(int arr[], int n){

	struct Pair ans;

	//swap sort
	for (int i = 0; i < n; i++)
	{
		if(arr[i] != i+1){
			
			if(arr[i]!=arr[arr[i]-1]){
				swap(arr[i],arr[arr[i]-1]);
				i--; //because it is still possible that we didn'y got correct element after swaping at position 'i'
			}		
		}
	}

	for (int i = 0; i < n; ++i)
	{	
		if(arr[i] != i+1){
			ans.missing = i+1;
			ans.repeating = arr[i];
			break;
		}

	}

	return ans;
}

int main(){

	int arr[] = {2,4,1,4,6,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	Pair ans = missingAndRepeating(arr,n);
	cout<<"Missing Number "<<ans.missing<<endl;
	cout<<"Repeating "<<ans.repeating;
	return 0;
}