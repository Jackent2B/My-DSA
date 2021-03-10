#include <iostream>
using namespace std;

void sorted_order(int arr[][], int n){
    if(n<=1)
        return;
    
        
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n][n];
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n;j++){
	            cin>>arr[i][j];
	        }
	    }
	    sorted_order(arr,n);
	}
	return 0;
}