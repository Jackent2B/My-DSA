#include<bits/stdc++.h>
using namespace std;

#define ll long long int
bool isValidIP(string &str){

	if(str.length()>3)
		return false;

	if(str.front()=='0' and str.length()>1)
		return false;

	ll val=stoll(str);
	return val>=0 and val<=255;
}

void computeAllValidIPAdress(string &str,vector<string> &res){

	for(ll i=1;i<=3 and i<str.length();i++)
	{
		//first part of IP address
		string first=str.substr(0,i);
		if(isValidIP(first))
		{
			//second part of IP address
			for(ll j=1;j<=3 and i+j<str.length();j++)
			{
				string second=str.substr(i,j);
				if(isValidIP(second))
				{
					//third part of IP address
					for(ll k=1;k<=3 and i+j+k<str.length();k++)
					{
						string third=str.substr(i+j,k);
						string fourth=str.substr(i+j+k);
						if(isValidIP(third) and isValidIP(fourth))
						{
							res.push_back(first+"."+second+"."+third+"."+fourth);

						}

					}

				}

			}

		}

	}
	return;

}

int main(){

	string str;
	cin>>str;
	vector<string> res;
    computeAllValidIPAdress(str,res);
    for(auto i:res)
		cout<<i<<"\n";
    return 0;
}