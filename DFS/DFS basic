
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define optimize() ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
const int N=1e5+123;
vector<int>graph[N];
vector<bool>vis(N);
void dfs(int node)
{
    // take action after entering vertex
    vis[node]=true;
    
    cout<<node<<" ";
    for(auto child:graph[node])
    {
        // take action after entering child
        if(vis[child])continue;

        dfs(child);
        // take action after existing child 
    }
    // take action after existing vertex;
}
int main()
{
    optimize();
    int t;
    cin >> t;
    while(t--) {
        int n,e;
        cin>>n>>e;
        for(int i=0;i<e;i++)
        {
            int x,y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);


        }
        int source;
        cin>>source;
        cout<<"DFS Traverse : ";
        dfs(source);

        
        
    }
}
