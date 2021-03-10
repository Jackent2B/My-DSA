#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start,int mid, int end){

    int n1 = mid-start+1;
    int n2 = end - mid;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; ++i)
        left[i] = arr[start+i];

    for (int i = 0; i < n2; ++i)
        right[i] = arr[mid+1+i];

    int i=0;
    int j=0;
    int k=start;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
         arr[k] = right[j];
            j++;   
        }
        k++;
    }

    while(i<n1){
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergerSort(int arr[], int start, int end){

    if(start<end){
        int mid = start + (end-start)/2; //to prevent overflow condition
        mergerSort(arr,start,mid);
        mergerSort(arr,mid+1,end);
        merge(arr,start,mid,end);        
    }
    return;
}

int main(){
    int arr[] = {4,5,10,20,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergerSort(arr,0,n-1);
    for (int i = 0; i < n; ++i)
        cout<<arr[i]<<" ";
    return 0;
}