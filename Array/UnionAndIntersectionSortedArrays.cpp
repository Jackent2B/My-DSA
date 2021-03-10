#include <bits/stdc++.h>
using namespace std;

//Note: this code is not suitable for handling duplicates in an array

int find_union_count(int arr1[], int arr2[], int n, int m){

	int i = 0;
	int j = 0;
	int count = 0;
	while(i<n && j<m){
		if(arr1[i]<arr2[j]){
			cout << arr1[i++]<<" ";
			count++;
		}
		else if (arr1[i]>arr2[j]){
			cout<< arr2[j++]<<" ";
			count++;
		}
		else{
		    cout<<arr1[i]<<" ";
			i++;
			j++;
		    count++;
		}
	}

	while(i<n){
		cout<<arr1[i++]<<" ";
		count++;
	}

	while(j<m){
		cout<<arr2[j++]<<" ";
		count++;
	}

	return count;
}


int main(){
 	int arr1[] = {1, 3, 4, 5, 7};
 	int n = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {2, 3, 5, 6};
  	int m = sizeof(arr2)/sizeof(arr2[0]);
    int unions = find_union_count(arr1,arr2,n,m);
    int intersection = n + m - unions;

    cout<<"Union is "<<unions<<" and intersection is "<<intersection<< endl; 
	return 0;
}