#include <bits/stdc++.h> 
using namespace std;

int largestPowerof2InRange(int n){

    int x = 0;
    while((1 << x)<=n)
        x++;
    return x-1;
}

int countSetBits(int n)
{
    if(n==0)
        return 0;
    int x = largestPowerof2InRange(n);
    int bits_UpTo_LastPowerOf2_InRange = pow(2,x-1)*x; // x * (1 << x-1); 
    int setBits = n-pow(2,x) + 1; // n - (1 << x-1) + 1;
    return bits_UpTo_LastPowerOf2_InRange + setBits + countSetBits(n-pow(2,x));
}

int main()
{
    int n = 14;
    cout << countSetBits(n);
 
    return 0;
}