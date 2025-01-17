#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define pb push_back
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
const ll N=1e5+10;
const ll INF=1e9+10;

vector<pair<ll,ll>>g[N];
vector<ll>level(N,INF);
ll n,m;
// 0-1 bfs e visited array er dorkar hoy na.
// jekhane jekhane edge ache sekhane inverse egde dite hobe 1 weight soho..then traverse korte hobe.

ll bfs()
{
    deque<ll>q;
    q.push_back(1);//source
    level[1]=0;
    while(!q.empty())
    {
        ll cur_v=q.front();
        q.pop_front();
        for(auto &u:g[cur_v])
        {
            ll child=u.first;
            ll weight=u.second;

            if(level[cur_v]+weight<level[child])
            {
                level[child]=level[cur_v]+weight;
                if(weight==1)
                {
                    q.push_back(child);
                }else
                {
                    q.push_front(child);
                }

            }
        }
    }

    return level[n]==INF?-1:level[n];
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(x==y)continue;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }

    cout<<bfs()<<endl;

}
