#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1];
int dep[N];  // depth of root is 1
int sz[N];   // size of the subtree

void dfs(int u, int p = 0) {
    par[u][0] = p; // amr parent
    dep[u] = dep[p] + 1;
    sz[u] = 1;

    // Set up binary lifting table
    for (int i = 1; i <= LG; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1]; //amar dada = baba[baba[amr]]
    }

    // Explore the tree
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }

    // Lift u to the same level as v
    for (int k = LG; k >= 0; k--) {
        if (dep[par[u][k]] >= dep[v]) {
            u = par[u][k];
        }
    }

    if (u == v) return u;

    // Find LCA using binary lifting
    for (int k = LG; k >= 0; k--) {
        if (par[u][k] != par[v][k]) {
            u = par[u][k];
            v = par[v][k];
        }
    }

    return par[u][0];
}

int kth(int u, int k) {
    assert(k >= 0);

    // Lift u by k levels using binary lifting
    for (int i = 0; i <= LG; i++) {
        if (k & (1 << i)) {
            u = par[u][i];
        }
    }

    return u;
}

int dist(int u, int v) {
    int l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);  // Distance calculation
}

// kth node from u to v, 0th node is u
int go(int u, int v, int k) {
    int l = lca(u, v);
    int d = dep[u] + dep[v] - (dep[l] << 1);

    assert(k <= d);

    // Determine if k is in the u -> lca(u, v) segment
    if (dep[l] + k <= dep[u]) {
        return kth(u, k);
    }

    // Otherwise, k is in the lca(u, v) -> v segment
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
}

void reset(int n) {
    // Clear graph and reset data structures
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    memset(dep, 0, sizeof(dep[0]) * (n + 1));
    memset(sz, 0, sizeof(sz[0]) * (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= LG; j++) {
            par[i][j] = 0;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        reset(n);

        // Input edges and construct tree
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // Run DFS from root (assuming node 1 is the root)
        dfs(1);
    }

    // Uncomment these lines to test distance queries
    // int q; cin >> q;
    // while (q--) {
    //   int u, v; cin >> u >> v;
    //   cout << dist(u, v) << '\n';
    // }

    return 0;
}

/*
        1
       / \
      2   3
     / \
    4   5

    1
     \
      2
       \
        3
         \
          4


        1
       / \
      2   3
     / \ / \
    4  5 6  7
*/
