#include <bits/stdc++.h>
using namespace std;

int MajorityElementCandidate(int arr[], int n){

    int maj_index = 0;
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if(arr[maj_index] == arr[i])
            count++;
        else
            count--; //if distinct elemnts are found

        if(count==0){
            maj_index = i;
            count=1;
        }
    }
    return arr[maj_index];
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
    	int x = MajorityElementCandidate(arr,n);

        //checking if the candidate for majority element is actually in majority
        //or not
        int countMjority = 0;
        for (int i = 0; i < count; ++i)
        {
            if(arr[i] == x)
                countMjority++;
        }

        if(countMjority >n/2)
            return x;
        else
            return 0;

	}
	return 0;
}