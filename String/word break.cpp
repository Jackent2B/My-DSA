#include <bits/stdc++.h>
using namespace std;
 
bool dictionaryContains(string word)
{
    string dictionary[]= 
            { "mobile", "samsung",  "sam",  "sung", "man",
            "mango",  "icecream", "and",  "go",   "i",
            "like",   "ice",      "cream" };
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i] == word)
            return true;
    return false;
}
 
// count of sentences possibles
int wordBreak(string s)
{
    int n = s.length();
    if (n == 0)
        return 0;

    // DP array
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j<=i; j++){
            string word_to_check = s.substr(j, i+1-j);
            if(dictionaryContains(word_to_check, wordDict)){
                if(j>0){
                    dp[i] = min(1000000007, dp[i] + dp[j-1]);
                }
                else{
                    dp[i] = dp[i] + 1;
                }
            }
        }
    }
    return dp[n - 1];
}
 
int main()
{
    string s = "ilikesamsung";
    cout<<wordBreak(s);
    return 0;
}