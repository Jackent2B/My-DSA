#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26; // No. of alphabets 
 
void firstnonrepeating(char str[])
{
    queue<char> q;
    int charCount[MAX_CHAR] = { 0 };
 
    for (int i = 0; str[i]; i++) {
 
        // push each character in queue
        q.push(str[i]);
 
        // increment the frequency count
        charCount[str[i] - 'a']++;
 
        // check for the non pepeating character
        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else {
                cout << q.front() << " ";
                break;
            }
        }
 
        if (q.empty())
            cout << "#" << " ";
    }
    cout << endl;
}
 
int main()
{
    char str[] = "aabc";
    firstnonrepeating(str);
    return 0;
}