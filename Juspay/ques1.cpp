#include<bits/stdc++.h>
using namespace std;

int parent[1001];
vector<int> adjlist[1001];
bool visited[1001];

void bfs(int u, int x)
{
    visited[u] = true;
    parent[u] = x;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(auto it: adjlist[u])
        {
            if(!visited[it])
            {
                visited[it]  = true;
                parent[it] = u;
                q.push(it);
            }
        }
    }
}
int main()
{
    int n, m, t, c;
    cin>>n>>m>>t>>c;
    
    int count = 0;
    int result = 0;
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
    bfs(1, -1);
    int x = n;
    
    while(parent[x]!=-1)
    {
        x = parent[x];
        count++;
    }

    count = count + 1;
    result = result + c;
    
    for(int i=1;i<count-1;i++)
    {
        x = result/t;
        if(x%2==0){
            result+=c;
        }
        else
        {
            result += (t-result%t);
            result+=c;
        }
    }
    cout<<result<<endl;
    return 0;
}