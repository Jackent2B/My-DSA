#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string x){
    
    int low = 0;
    int high = x.length()-1;
    while(low<high){
        if(x[low] != x[high])
            return false;
        low++;
        high--;
    }
    return true;
}
 
void allPalPartitions(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    for (int i = 0; i < s.length(); ++i)
    {
        string prefix = s.substr(0,i+1);
        string rest = s.substr(i+1);
        if(isPalindrome(prefix)){
            allPalPartitions(rest, ans + " "+ prefix);
        }
    }

}


int main()
{
    string s = "nitin";
    string ans = " ";
    allPalPartitions(s,ans);
    return 0;
}