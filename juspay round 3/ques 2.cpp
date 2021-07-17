#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

vector<pair<int,int>> adjlist[1001];
ll par[1001];
struct prll{
    ll u;
    ll d;

    public:
        prll(ll a,ll b){
            u=a;    
            d=b;
        }
};
class compfunc{
    public:
        ll operator()(const prll &x,const prll &y){
            if(x.d>y.d){
                return true; 
            }
            else{
                return false;
            }
        }
};
void init(ll arr[],ll x,ll y)
{
    for(int i=0;i<=y;i++)
    {
        arr[i]=x;
    }
}
ll dijkstaraAlgo(ll a,ll v,ll n)
{
    ll distance[n+1];
    //ll par[n+1]={0};
    init(distance,1000000000000000009,n);
    distance[a]=0;
    priority_queue<prll, vector<prll>, compfunc>prq;
    for(ll i=1;i<=n;i++)
    {
        prq.push(prll(i,distance[i]));
    }
    prll mi=prq.top();
    while(!prq.empty())
    {
        prll tmin=prq.top();
        prq.pop();
        for(ll i=0;i<adjlist[tmin.u].size();i++)
        {
            if(distance[adjlist[tmin.u][i].first]>distance[tmin.u]+adjlist[tmin.u][i].second)
            {
                par[adjlist[tmin.u][i].first]=tmin.u;
                distance[adjlist[tmin.u][i].first]=distance[tmin.u]+adjlist[tmin.u][i].second;
                //changepriority(prq,adjlist[tmin.u][i].first,distance[adjlist[tmin.u][i].first]);
                priority_queue<prll, vector<prll>, compfunc>nprq;
                ll a=adjlist[tmin.u][i].first;
                ll dis=distance[adjlist[tmin.u][i].first];
                while(((prq.top()).u)!=a)
                {
                    nprq.push(prll(((prq.top()).u),((prq.top()).d)));
                    prq.pop();
                }
                nprq.push(prll((prq.top()).u,dis));
                prq.pop();
                while(!nprq.empty())
                {
                    prq.push(prll((nprq.top()).u,(nprq.top()).d));
                    nprq.pop();
                }
            }
        }
    }
    return distance[v];
}

int main()
{
    int tc=1, n, m, u, v, a, x, count;
    while(tc--)
    {
        count = 0;
        cin>>n;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            mp[a] = i+1;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v>>x;
            adjlist[mp[u]].push_back({mp[v], x});
        }
        cin>>u>>v;
        u = mp[u];
        v = mp[v];
        cout<<dijkstaraAlgo(u, v, n)<<endl;
    }
    return 0;
}