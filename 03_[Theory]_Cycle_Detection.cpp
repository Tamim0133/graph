#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];

bool dfs(int vartex, int par)
{
    vis[vartex] = true;
    bool loopExists = false;
    for(int child : g[vartex])
    {
        if(vis[child] and child == par) continue;
        if(vis[child]) return true;
        loopExists |= dfs(child, vartex);
    }
    return loopExists;
}


void solve()
{
    int n , e; cin >> n >> e;

    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        g[i].clear();
    }

    for(int i = 0; i < e; i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1);
}

int main()
{
    int t= 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}