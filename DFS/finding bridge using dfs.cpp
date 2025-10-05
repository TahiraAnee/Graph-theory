//-----------Time Complexity: O(n+m)------//
//----------Tarjan's algorithm-------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
vector<ll> adj[N];
bool visited[N];
ll disc[N], low[N];
ll n, e;
ll timer = 0; 

void bridge(ll i,ll p) {
    visited[i] = true;
    disc[i] = low[i] = ++timer;

    for(auto &u:adj[i]){
        if(u == p) continue;

        if(visited[u]) {
            low[i] = min(low[i], disc[u]); 
        } else {
            bridge(u,i);
            low[i] = min(low[i], low[u]);
            if(low[u] > disc[i]) {
                cout << i << " " << u << endl;
            }
        }
    }
}

void finding() {
    for(ll i=1;i<=n;i++) {
        visited[i] = false;
        disc[i] = 0;
        low[i] = 0;
    }
    for(ll i=1;i<=n;i++) {
        if(!visited[i]) {
            bridge(i,-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    for(ll i=1;i<=e;i++) {
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    finding();
}
