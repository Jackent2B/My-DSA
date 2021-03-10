#include <bits/stdc++.h>
using namespace std;

int answer(int n1, int arr1[], int n2, int arr2[]){
	int ans = 0;
	
	int i = 0; 
	int j = 0;

	int sum1 = 0;
	int sum2 = 0;
	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			sum1 = sum1 + arr1[i];
			i++;
		}
		else if(arr1[i]>arr2[j]){
			sum2 = sum2 + arr2[j];
			j++;
		}
		else{
			ans = ans + max(sum1,sum2);
			sum1=arr1[i];
			sum2=arr2[j];
			i++;
			j++;
		}
	}

	while(i<n1){
		sum1 = sum1 + arr1[i];
	}
	while(j<n2){
		sum2 = sum2 + arr2[j];
	}

	ans = ans + max(sum1,sum2);
	return ans;
}

int main(){

	while(true){

	int n1;
	cin>>n1;

	if(n1==0)
		break;

	int arr1[n1];
	for (int i = 0; i < n1; ++i)
		cin>>arr1[i];

	int n2;
	cin>>n2;
	int arr2[n2];
	for (int i = 0; i < n2; ++i)
		cin>>arr2[i];	

	cout<<answer(n1, arr1, n2, arr2)<<'\n';
	}
	return 0;
}