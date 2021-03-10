#include <bits/stdc++.h>
using namespace std;


bool isSubset(int arr1[], int arr2[], int n1, int n2){
	
	set <int> s;

	for (int i = 0; i < n1; ++i)
		s.insert(arr1[i]);

	for (int i = 0; i < n2; ++i)
	{
		if(s.find(arr2[i]) == s.end())
			return 0;
	}	
	return 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n1,n2;
		cin>>n1>>n2;
		int arr1[n1], arr2[n2];
		for (int i = 0; i < n1; ++i)
			cin>>arr1[i];
		for (int i = 0; i < n2; ++i)
			cin>>arr2[i];
		if(isSubset(arr1,arr2,n1,n2))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
	return 0;
}