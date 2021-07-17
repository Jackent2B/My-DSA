#include <bits/stdc++.h>
using namespace std;


//tuf youtube video
//moore voting algorithm
int findAns(int element,int arr[], int n){
    int count = 0;
    for(int i=0; i<n;i++){
        if(arr[i] == element)
            count++;
    }
    
    if(count > n/2)
        return element;
    else 
        return -1;
}

int majorityElement(int arr[], int n)
{
   
	int maj_index = 0, count = 1;
    for (int i = 1; i < n; i++) {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
	//element that we got will be a candidate for to be a majotiy element
	//so we will confirm it whether it is a majority element or not using findAns() function
    return findAns(a[maj_index],arr,n);
}

int main(){
	int arr[] = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5}; 
	int n = sizeof(arr)/sizeof(arr[0]);
    cout << majority_element(arr,n) << endl; 
	return 0;
}