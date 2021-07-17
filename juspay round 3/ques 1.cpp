#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
bool visi[1001];
bool bfs(int u, int v)
{
    visi[u] = true;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(auto j: adj[u])
        {
            if(!visi[j])
            {
                visi[j]  = true;
                if(j==v)
                    return true;
                q.push(j);
            }
        }
    }
    return false;
}
int main()
{
    int tc=1, n, m, u, v, a;
    while(tc--)
    {
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
            cin>>u>>v;
            adj[mp[u]].push_back(mp[v]);
        }
        cin>>u>>v;
        u = mp[u];
        v = mp[v];
        if(bfs(u, v))
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}