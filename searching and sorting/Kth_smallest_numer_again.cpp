#include <bits/stdc++.h>
using namespace std;
int main(){
    int t ;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<pair<int,int>> vec;
        
        while(n--){
            int a,b;
            cin>>a>>b;
            vec.push_back({a,b});
        }
        //sort the vector
        sort(vec.begin(),vec.end());

        //merge overlaping intervals;
        int temp = 0;
        for (int i = 1; i < vec.size(); ++i)
        {
            if(vec[temp].second >= vec[i].first){
                vec[temp].second = max(vec[temp].second,vec[i].second);
            }
            else{
                temp++;
                vec[temp] = vec[i];
            }
        }

        // find element
        while(q--){
            int k;
            cin>>k;
            int ans = -1;

            for (int i = 0; i <= temp; i++)
            {
                if(( vec[i].second - vec[i].first + 1)>=k){
                    ans = vec[i].first + k-1;
                    break;
                }
                else{
                    k = k - ( vec[i].second - vec[i].first + 1 );
                    
                }
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}