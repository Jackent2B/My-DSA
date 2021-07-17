#include <bits/stdc++.h>
using namespace std;
 
int versionCompare(string v1, string v2)
{
    int vnum1 = 0, vnum2 = 0;
 
    int i = 0;
    int j = 0;
    while(i<v1.length() || j<v2.length()) {

        while (i < v1.length() && v1[i] != '.') {
            vnum1 = vnum1 * 10 + (v1[i] - '0');
            i++;
        }
 
        while (j < v2.length() && v2[j] != '.') {
            vnum2 = vnum2 * 10 + (v2[j] - '0');
            j++;
        }
 
        if (vnum1 > vnum2)
            return 1;
        if (vnum2 > vnum1)
            return -1;
 
        vnum1 = vnum2 = 0;
        i++;
        j++;
    }
    return 0;
}
 
int main()
{
    string version1 = "1.0.3";
    string version2 = "1.0.7";
 
    if (versionCompare(version1, version2) < 0)
        cout <<"v1 is smaller";
    else if (versionCompare(version1, version2) > 0)
        cout << "v2 is smaller";
    else
        cout << "Both version are equal";
    return 0;
}