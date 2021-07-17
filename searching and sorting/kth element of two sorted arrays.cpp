#include <bits/stdc++.h>
using namespace std;

int KthSmallestOfTwoSortedArrays(int ar1[],int ar2[],int n1,int n2, int k){
    if(n1>n2) return KthSmallestOfTwoSortedArrays(ar2,ar1,n2,n1, k);
    
    int low = min(0,k-n2); // for handling edge cases
    int high = min(k,n1); // for handling edge cases

    while(low <= high){
        int cut1 = low + (high-low)/2;
        int cut2 = (n1 + n2 + 1)/2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : ar1[cut1-1] ;
        int left2 = cut2 == 0 ? INT_MIN : ar2[cut2-1] ;
        int right1 = cut1 == n1 ? INT_MAX :  ar1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : ar2[cut2];

        if(left1<=right2 && left2<= right1){
                return max(left1,left2);
        }
        else if(left1>right2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }
    return 0;
}

int main()
{
    int ar1[] = {7,12,14,15};
    int ar2[] = {1,2,3,4,9,11};  
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int k = 5; //find 5th smallest element
    // sorted cobined array : 1 2 3 4 7 9 11 12 14 15
    // Ans: 7
    cout << KthSmallestOfTwoSortedArrays(ar1, ar2, n1, n2, k);
    return 0;
}
