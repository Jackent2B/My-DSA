#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    
    int rounds;
    cin>>rounds;
    while(rounds--){
        int power;
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