#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n; //No of soldiers

    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i]; // array defining the power of each soldier
    
    int rounds; // No. of Rounds
    cin>>rounds;
    while(rounds--){
        int power; // Power of bishu
        cin>>power;

        int sum = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(arr[i]<=power){
                sum = sum + arr[i];
                count++;
            }
        }
    cout<<count<<" "<<sum<<endl;
    }
    return 0;
}