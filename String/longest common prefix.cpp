//Method 1
#include<bits/stdc++.h>
using namespace std;
 
string longestCommonPrefix(string ar[], int n)
{
 
    if (n == 0)
        return "";
 
    if (n == 1)
        return ar[0];
 
    sort(ar, ar + n);
    int en = min(ar[0].size(),ar[n - 1].size());
 
    // Now the common prefix in first and
    // last string is the longest common prefix
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;
 
    string pre = first.substr(0, i);
    return pre;
}
 
int main()
{
    string ar[] = {"geeksforgeeks", "geeks",
                           "geek", "geezer"};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << "The longest common prefix is: "
         << longestCommonPrefix(ar, n);
    return 0;
}
 
// Method 2 

// #include<bits/stdc++.h>
// using namespace std;
  
// int findMinLength(string arr[], int n)
// {
//     int min = INT_MAX;
  
//     for (int i=0; i<=n-1; i++)
//         if (arr[i].length() < min)
//             min = arr[i].length();
//     return(min);
// }
  
// bool allContainsPrefix(string arr[], int n, string str,
//                        int start, int end)
// {
//     for (int i=0; i<=n-1; i++)
//         for (int j=start; j<=end; j++)
//             if (arr[i][j] != str[j])
//                 return (false);
//     return (true);
// }
  
// // A Function that returns the longest common prefix
// // from the array of strings
// string commonPrefix(string arr[], int n)
// {
//     int index = findMinLength(arr, n);
//     string prefix; // Our resultant string
  
//     // We will do an in-place binary search on the
//     // first string of the array in the range 0 to
//     // index
//     int low = 0, high = index;
  
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
  
//         if (allContainsPrefix (arr, n, arr[0], low, mid))
//         {
//             // If all the strings in the input array contains
//             // this prefix then append this substring to
//             // our answer
//             prefix = prefix + arr[0].substr(low, mid-low+1);
  
//             // And then go for the right part
//             low = mid + 1;
//         }
  
//         else // Go for the left part
//             high = mid - 1;
//     }
  
//     return (prefix);
// }
  
// int main()
// {
//     string arr[] = {"geeksforgeeks", "geeks",
//                     "geek", "geezer"};
//     int n = sizeof (arr) / sizeof (arr[0]);
  
//     string ans = commonPrefix(arr, n);
  
//     if (ans.length())
//         cout << ans;
//     else
//         cout << "There is no common prefix";
//     return 0;
// }