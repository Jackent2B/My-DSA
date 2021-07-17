#include <bits/stdc++.h>
using namespace std;

int maxsum(int arr[], int n)
{
   int including = arr[0]; //max sum including the prev element.
   int excluding = 0; //max sum excluding the prev element.
   int excluding_next;

   for (int i = 0; i < n; i++)
   {
   		excluding_next = max(including,excluding);
   		including = excluding + arr[i]; //if you are adding the current element, 
   										//that means you must have excluded the previous element
   		excluding = excluding_next;
   }

   return max(excluding,including);
    
}

int main(){
	int arr[] = {5,5,100,10,5}; 
	int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxsum(arr,n) << endl; 
	return 0;
}