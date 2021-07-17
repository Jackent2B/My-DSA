#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

vector<int> adj[1001];
int pass[1001];
bool visi[1001];
void dfs(int u, int v, int x)
{
    visi[u] = true;
    if(u==v)
    {
        pass[x]=1;
        return;
    }
    for(auto j: adj[u])
    {
        if(!visi[j])
        {
            visi[j] = true;
            dfs(j, v, u);
        }
        else
        {
            if(j==v)
                pass[u] = 1;
        }
    }
}

int main()
{
    int tc=1, n, m, u, v, a, x, cnt;
    while(tc--)
    {
        cnt = 0;
        cin>>n;
        ll arr[n+1];
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            mp[arr[i]] = i;
        }
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[mp[u]].push_back(mp[v]);
        }
        cin>>u>>v;
        u = mp[u];
        v = mp[v];
        memset(pass, 0, sizeof(pass));
        dfs(u,v,0);
        for(int i =1;i<=n;i++)
        {
            if(pass[i]==1)
            {
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}