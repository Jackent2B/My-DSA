#include <bits/stdc++.h> 
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k)
{
    queue<int>  q;
  
    int start = 0;
    int end = 0;

    while(end < n){
    
        //calculation
        if(arr[end]<0)
            q.push(arr[end]);
        
        //sliding till the window size is not complete
        if(end - start +1 <k)
            end++;

        else if(end - start + 1 == k){
            //ans based on calculation 
            if(q.size()==0)
                cout<<'0'<<" ";
            else if(arr[start] == q.front()){    
                cout<<q.front()<<" ";
                q.pop(); //to remove first element
            }

            else cout<<q.front()<<" ";
            //slidng the window
            start++;
            end++;
        }
    } 
}
  
int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printFirstNegativeInteger(arr, n, k);
    return 0;
}