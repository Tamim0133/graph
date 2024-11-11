#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int d[N], h[N], par[N];

void dfs(int v, int p = -1){
    par[v] = p;
    for(int x : g[v])
    {
        if(x == p) continue;
        d[x] = d[v] + 1;
        dfs(x, v);
        h[v] = max(h[v] , h[x] + 1);
    }
}
void reset(int n) {
    // Clear adjacency list for all nodes
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    // Reset depth (d), height (h), and parent (par) arrays
    fill(d, d + n + 1, 0);
    fill(h, h + n + 1, 0);
    fill(par, par + n + 1, -1);
}


void solve()
{
    int n;
    cin >> n;

    reset(n);

    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
}

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}