#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visi[1001];
bool visited[1001];
int par[1001];
int dist[1001];
int low[1001];

int flag;
set< pair<int,int> > st;
void bridgeutil(int u, int x)
{
    visited[u] = true;
    dist[u] = low[u] = ++flag;
    for(auto j: adj[u])
    {
        if(!visited[j])
        {
            bridgeutil(j, u);
            low[u] = min(low[u], low[j]);
            if(low[j]>dist[u])
            {
                st.insert({u,j});
            }
        }
        else if(j!=x)
            low[u] = min(low[u], low[j]);
    }
}
void bfs(int u, int x)
{
    visi[u] = true;
    par[u] = x;
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
                par[j] = u;
                q.push(j);
            }
        }
    }
}
bool bfsedge(int u, int x, int a, int b, int n)
{
    visited[u] = true;
    par[u] = x;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(auto j: adj[u])
        {
            //cout<<j<<endl;
            if((j!=a || u!=b) && (j!=b || u!=a))
            {
                if(!visited[j])
                {
                    visited[j] = true;
                    par[j] = u;
                    q.push(j);
                    if(j==n)
                        return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    int tc=1, n, m, t, c, cnt, ans, u, v, tans, sans,a,b;
    while(tc--)
    {
        sans = -1;
        vector< pair<int,int> > v1;
        cin>>n>>m>>t>>c;
        cnt = 0, ans =0;
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        flag = 0;
        memset(visited, false, sizeof(visited));
        bridgeutil(1,-1);
        bfs(1, -1);
        int x = n;
        while(par[x]!=-1)
        {
            v1.push_back({x, par[x]});
            x = par[x];
            cnt++;
        }
        cnt+=1;
        ans+=c;
        for(int i=1;i<cnt-1;i++)
        {
            x = ans/t;
            if(x%2==0)
                ans+=c;
            else
            {
                ans += (t-ans%t);
                ans+=c;
            }
        }
        for(auto j: v1)
        {
            a = j.first;
            b = j.second;
            if(st.find({a,b})==st.end() && st.find({b,a})==st.end())
            {
                memset(visited, false, sizeof(visited));
                //cout<<a<<" "<<b<<endl;
                if(bfsedge(1, -1, a, b, n))
                {
                    cnt = 0;
                    tans = 0;
                    x = n;
                    while(par[x]!=-1)
                    {
                        x = par[x];
                        cnt++;
                    }
                    cnt++;
                    tans+=c;
                    for(int i=1;i<cnt-1;i++)
                    {
                        x = tans/t;
                        if(x%2==0)
                            tans+=c;
                        else
                        {
                            tans += (t-tans%t);
                            tans+=c;
                        }
                    }
                    //cout<<cnt<<endl;
                    if(tans!=ans)
                    {
                        if(sans == -1)
                            sans = tans;
                        else
                            sans = min(sans, tans);
                    }
                }
            }
        }
        cout<<sans<<endl;
    }
    return 0;
}