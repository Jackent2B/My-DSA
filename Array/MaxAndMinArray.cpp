#include <bits/stdc++.h>
using namespace std;

void getMinMax(int arr[], int n){
	int cur_min = arr[0];
	int cur_max = arr[0];
    int i=0;
    while(i<n)
    {
        if(A[i] > curr_max)
        {
            curr_max=A[i];
        }
        
        if(A[i] < curr_min)
        {
            curr_min=A[i];
        }
        
        i+=1;
    }
	cout<<"Max element is "<<max<<" and min element is "<<min; 
}

// struct minmax{
//     int min;
//     int max;
// };
// struct minmax get_minmax(vector<int> &A, int left, int right){
//     struct minmax res, lres,rres;
//     int mid;
//     if(left == right){
//         res.min = A[left];
//         res.max = A[left];
//         return res;
//     }
//     if(right == left +1){
//         if(A[right] > A[left]){
//             res.min = A[left];
//             res.max = A[right];
//         }
//         else{
//             res.min = A[right];
//             res.max = A[left];
//         }
//         return res;
//     }
//     mid = (left+right)/2;
//     lres = get_minmax(A,left,mid);
//     rres = get_minmax(A,mid+1,right);
//     if(lres.min < rres.min)
//         res.min = lres.min;
//     else
//         res.min = rres.min;
//     if(lres.max> rres.max)
//         res.max = lres.max;
//     else
//         res.max = rres.max;
//     return res;
    
// }
// int Solution::solve(vector<int> &A) {
//     struct minmax res = get_minmax(A, 0, A.size()-1);
//     return res.min+res.max;
// }

int main(){
	 int arr[] = { 1000, 11, 445, 
                  1, 330, 3000 };
    int n = sizeof(arr)/sizeof(arr[0]);
    getMinMax(arr,n);
	return 0;
}