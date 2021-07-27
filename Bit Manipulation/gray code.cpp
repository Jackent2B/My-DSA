#include <bits/stdc++.h>
using namespace std;

// Method1:
// vector<int> grayCode(int n) {
//     vector<int> v;       
//     for(int i=0;i<(1<<n);i++){
//         v.push_back(i^(i>>1));
        
//         // 00 ^ (00)
//         // 01 ^ (00)
//         // 10 ^ (01)
//         // 11 ^ (01)
//     }
//     return v;
// }

// Reference pepcoding : Method 2
vector<string> generateGrayarr(int n)
{
    vector <string> basevector;
    if(n<=0)
        return basevector;

    if(n==1){
        basevector.push_back("0");
        basevector.push_back("1");
        return basevector;   
    }

    vector <string> prevVector = generateGrayarr(n-1);
    vector <string> newVector;

    for(int i = 0; i < prevVector.size(); i++){
        string temp = "0" + prevVector[i];
        newVector.push_back(temp);
    }

    // concatenating 1 after reversing
    for(int i = prevVector.size()-1; i >= 0; i--){
        string temp = "1" + prevVector[i];
        newVector.push_back(temp);
    }
    return newVector;
}

int convertBinaryToDec(string s){
    int num = 0;
    int pos = s.length()-1;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '1')
            num = num + 1*(1<<pos);
        else if(s[i] == '0')
            num = num + 0*(1<<pos);
        pos--;
    }
    return num;
}
 
int main()
{
    vector<string> graycode = generateGrayarr(3);
    //vector<num> ans;
    for (int i = 0; i < graycode.size(); ++i)
    {
      int x = convertBinaryToDec(graycode[i]);
      cout<<x<<" ";
      //ans.push_back(x);
    }

    return 0;
}