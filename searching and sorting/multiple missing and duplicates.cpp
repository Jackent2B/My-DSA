#include <bits/stdc++.h>
using namespace std;

//refer: aditya vermas
vector<int> missing(int arr[], int n){

	vector<int> missing;

	//swap sort
	for (int i = 0; i < n; i++)
	{
		if(arr[i] != i+1){
			
			if(arr[i]!=arr[arr[i]-1]){
				swap(arr[i],arr[arr[i]-1]);
				i--;
			}		
		}
	}

	for (int i = 0; i < n; ++i)
	{	
		if(arr[i] != i+1){
			missing.push_back(i+1);
			
		}

	}

	return missing;
}

vector<int> repeating(int arr[], int n){

	vector<int> repeating;

	//swap sort
	for (int i = 0; i < n; i++)
	{
		if(arr[i] != i+1){
			
			if(arr[i]!=arr[arr[i]-1]){
				swap(arr[i],arr[arr[i]-1]);
				i--;
			}		
		}
	}

	for (int i = 0; i < n; ++i)
	{	
		if(arr[i] != i+1){
			repeating.push_back(arr[i]);
		}

	}

	return repeating;
}


int main(){

	int arr[] = {2,4,1,4,6,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> missing = missing(arr,n);
	vector<int> repeating = repeating(arr,n);
	
	for(int i=0; i<missing.size(); i++)
	    cout<<missing[i];
    for(int i=0; i<repeating.size(); i++)
	    cout<<repeating[i];

	return 0;
}