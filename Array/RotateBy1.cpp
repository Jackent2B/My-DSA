#include <bits/stdc++.h>
using namespace std;

void rotateBy1(int arr[], int n){
	int first = arr[n-1];

	for (int i = n-1; i >0; i--)
		arr[i] = arr[i-1];
	
	arr[0] = first;

	//print array

	for (int i = 0; i < n; i++)
		cout<<arr[i]<<" ";

}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n;i++)
            cin>>arr[i];
        rotateBy1(arr,n);
        cout<<endl;
    }
	return 0;
}