#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
        
	vector<pair<string,int>> vec;
    
    vec.push_back({"M",1000});
    vec.push_back({"CM",900});
    vec.push_back({"D",500});
    vec.push_back({"CD",400});
    vec.push_back({"C",100});
    vec.push_back({"XC",90});
    vec.push_back({"L",50});
    vec.push_back({"XL",40});
    vec.push_back({"X",10});
    vec.push_back({"IX",9});
    vec.push_back({"V",5});
    vec.push_back({"IV",4});
    vec.push_back({"I",1});
    
    string ans;
    for(int i=0; i<vec.size(); i++){
        
        // No. of times the string has to be added
        int x = num/vec[i].second; 

        for(int a=0; a<x; a++){
            ans=ans+vec[i].first;
        }
        
        num = num % vec[i].second;
        
        if(num==0)
            break; 
    }
    return ans;   
}


int main(){
	int num = 2944;
	cout<<IntegerToRoman(num);
	return 0;
}