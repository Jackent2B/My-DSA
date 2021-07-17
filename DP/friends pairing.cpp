#include <bits/stdc++.h>
using namespace std;

//Refernce: Pepcoding sumeet sir

int friendsPair(int n){

	// Space Complexity : O(1)
	// int a = 1, b = 2, c = 0;
	//    if (n <= 2) {
 	//        return n;
 	//    }
 	//    for (int i = 3; i <= n; i++) {
 	//        c = b + (i - 1) * a;
 	//        a = b;
 	//        b = c;
 	//    }
 	//    return c % 1000000007;

	// Space Complexity: O(n) 

        	int arr[n+1] = {0};
        	arr[1] = 1;
        	arr[2] = 2;
        
        	for (int i = 3; i < n+1; i++)
        	{
        		arr[i] = (arr[i-1] + (i-1)*arr[i-2])%1000000007;
        	}
        	return arr[n];
}

int main(){
	int n = 3;
	cout<<friendsPair(n);
	return 0;
}