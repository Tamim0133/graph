#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 9, LG = 18;

vector<pair<int, int>> g[N];  // Graph to store roads and their lengths
int par[N][LG + 1];
int min_road[N][LG + 1];
int max_road[N][LG + 1];
int dep[N];

void dfs(int u, int p = 0, int weight = 0) {
    par[u][0] = p; // amr parent
    dep[u] = dep[p] + 1;
    min_road[u][0] = weight; // amr par e jaoyar wt
    max_road[u][0] = weight;

    for (int i = 1; i <= LG; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];//amar dada = baba[baba[amr]]
        min_road[u][i] = min(min_road[u][i - 1], min_road[par[u][i - 1]][i - 1]);// min till amar dada = min(baba[baba[amr]] , baba[amr])
        max_road[u][i] = max(max_road[u][i - 1], max_road[par[u][i - 1]][i - 1]);
    }

    for (auto [v, w] : g[u]) {
        if (v != p) {
            dfs(v, u, w);
        }
    }
}

pair<int, int> lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);

    int min_len = INT_MAX, max_len = 0;

    for (int k = LG; k >= 0; k--) {
        if (dep[par[u][k]] >= dep[v]) {
            min_len = min(min_len, min_road[u][k]);
            max_len = max(max_len, max_road[u][k]);
            u = par[u][k];
        }
    }

    if (u == v) return {min_len, max_len};

    for (int k = LG; k >= 0; k--) {
        if (par[u][k] != par[v][k]) {
            min_len = min({min_len, min_road[u][k], min_road[v][k]});
            max_len = max({max_len, max_road[u][k], max_road[v][k]});
            u = par[u][k], v = par[v][k];
        }
    }

    min_len = min({min_len, min_road[u][0], min_road[v][0]});
    max_len = max({max_len, max_road[u][0], max_road[v][0]});

    return {min_len, max_len};
}

void reset(int n) {
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    memset(dep, 0, sizeof(dep[0]) * (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= LG; j++) {
            par[i][j] = 0;
            min_road[i][j] = INT_MAX;
            max_road[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    reset(n);

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(1);

    int k;
    cin >> k;

    while (k--) {
        int u, v;
        cin >> u >> v;
        auto [min_len, max_len] = lca(u, v);
        cout << min_len << " " << max_len << '\n';
    }

    return 0;
}
