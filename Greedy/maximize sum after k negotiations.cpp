    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        for(int i =0; i<n; i++){
            if(a[i]>=0)
                break;
            if(k>0){
                k--;
                a[i] = -1*a[i];
            }
        }
        
        sort(a,a+n);
        int sum = 0;
        if(k%2==0){
            for(int i=0; i<n; i++){
                sum = sum + a[i];
            }
        }
        else{
            sum = sum + a[0]*-1;
            for(int i=1; i<n; i++){
                sum = sum + a[i];
            }
        }
        return sum;
    }