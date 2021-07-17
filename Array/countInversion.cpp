#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int start,int mid, int end){

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
    int countInversions = 0;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;   
            countInversions = countInversions + (n1 - i);
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
    return countInversions;
}

int mergerSort(int arr[], int start, int end){
    if(end - start + 1 < 2)
        return 0;
    int countInversions = 0;
    int mid = start + (end-start)/2; //to prevent overflow condition
    countInversions += mergerSort(arr,start,mid);
    countInversions += mergerSort(arr,mid+1,end);
    countInversions += merge(arr,start,mid,end);
    return countInversions;
}

int main(){
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int countInversions = mergerSort(arr,0,n-1);
    for (int i = 0; i < n; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Count Inversions "<<countInversions<<endl;
    return 0;
}