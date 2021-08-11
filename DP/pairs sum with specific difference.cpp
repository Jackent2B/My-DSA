
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
{
    // Your code goes here 
    sort(arr, arr+N, greater<int>());
    int i=0; 
    int sum = 0;
    while(i<N-1){
        if(abs(arr[i] - arr[i+1]) <K){
            sum = sum + arr[i] + arr[i+1];
            i = i+2;
        }
        else{
            i++;
        }
    }
    return sum;
}