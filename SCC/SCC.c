#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int>adj[N],adj_rev[N];
vector<bool>visited(N);


void dfsG(int source,vector<int>&order)
{
    visited[source]=true;

    for(auto u:adj[source])
    {
        if(!visited[u])
        {
            dfsG(u,order);
        }
    }
    order.push_back(source);
}
void dfsGT(int source,vector<int>&component)
{
    visited[source]=true;
   // cout<<source<<" ";
    component.push_back(source);
    for(auto u:adj_rev[source])
    {
        if(!visited[u])
        {
            dfsGT(u,component);
        }
    }
  //  cout<<source<<" ";
   

}
int main()
{
   
    int n,e;
    cin>>n>>e;
    vector<vector<int>>scc;
    vector<int>order,component;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

   fill(visited.begin(), visited.end(), 0);

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfsG(i,order);
        }
    }

    fill(visited.begin(), visited.end(), 0);
    reverse(order.begin(),order.end());

    for(int i=1;i<=n;i++)
    {
        if(!visited[order[i-1]])
        {
            dfsGT(i,component);
           scc.push_back(component);
            component.clear();
           //cout<<endl;
        }
    }
    cout<<scc.size()<<endl;
    for(auto sc:scc)
    {
        for(int u:sc)
        {
            cout<<u<<" ";
        }cout<<endl;
    }
}
