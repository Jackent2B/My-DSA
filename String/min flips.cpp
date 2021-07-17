/*
Algorithm: 
We can solve this problem by considering all possible results, 
As we are supposed to get alternate string, there are only 2 possibilities,
alternate string starting with 0 and alternate string starting with 1.
We will try both cases and choose the string which will require minimum number of flips 
as our final answer. 
*/

#include <bits/stdc++.h>
using namespace std;

char flip(char expected){
    if(expected == '1')
        return '0';
    else
        return '1';
} 

int FlipWithStartingCharcter(string s, char expected){
    
    int count =0;
    for (int i = 0; i < s.length(); ++i)
    {
        if(s[i] != expected){
            count++;
        }        
        expected = flip(expected);
    }
    return count;
}

int minFlips(string s){

    //  return minimum of following two
    //  1) flips when alternate strign starts with 0
    //  2) flips when alternate strign starts with 1
    return min(FlipWithStartingCharcter(s, '0'),
               FlipWithStartingCharcter(s, '1'));
}

int main()
{    
    string str = "0001010111";
    cout << minFlips(s);
    return 0;
}