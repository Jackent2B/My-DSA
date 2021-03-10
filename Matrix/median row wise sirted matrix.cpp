#include<bits/stdc++.h> 
using namespace std; 
  
const int MAX = 100; 
  
//Reference: himanshu jhab youtube video   
int binaryMedian(int m[][MAX], int r ,int c) 
{ 
    // code here       
    int minimum = INT_MAX, maximum = INT_MIN; 
    for (int i=0; i<r; i++) 
    { 
        minimum = min(minimum,m[i][0]);  //smallest elemnt of the matrix;
        maximum = max(maximum,m[i][c-1]); //largest element of the matrix;
    } 
  
    int desired_element = (r * c + 1) / 2; 

    //binary search in range [minimum to maximum]
    while (minimum < maximum) 
    { 
        int mid = minimum + (maximum - minimum) / 2; 
        int count = 0; 
  
        // Find count of elements smaller than mid 
        for (int i = 0; i < r; ++i) 
            count += upper_bound(m[i], m[i]+c, mid) - m[i];  
        if (count < desired_element) 
            minimum = mid + 1; 
        else
            maximum = mid; 
    } 
    return minimum;  
} 

int main() 
{ 
    int r = 3, c = 3; 
    int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} }; 
    cout << "Median is " << binaryMedian(m, r, c) << endl; 
    return 0; 
} 