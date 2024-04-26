#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define optimize() ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
const int N=1e5+12;
vector<int>graph[N];
int visited[N];
int level[N];
int parent[N];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visited[source]=1;
    level[source]=0;
    parent[source]=-1;

    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        //cout<<"BFS ORDER : ";
        cout<<curr<<" ";
        for(auto v:graph[curr])
        {
            if(!visited[v])
            {
                q.push(v);
                level[v]=level[curr]+1;
                visited[v]=1;
                parent[v]=curr;
            }
        }
    }
}
int main()
{
    optimize();
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);
    cout<<endl;
    int x;
    while(cin>>x && x!=0){
    if(!visited[x])
    {
        cout<<"No path!"<<endl;
    }
    else
    {
        vector<ll>path;
        for(int i=x;i!=-1;i=parent[i])
        path.push_back(i);

        reverse(path.begin(),path.end());
        cout<<"Path :";
        for(auto u:path)cout<<u<<" ";
    }cout<<endl;
    }


}