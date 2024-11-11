/*
Diameter of a tree = max(Distance between any two nodes)

1. With any root find the maximum depth node . [this will be one end of the diameter]
2. Using max_depth_node, find maximum depth. [this will be another end of the diameter]
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int d[N], h[N];

void dfs(int vartex, int par = 0){
    for(int child : g[vartex])
    {
        if(child == par) continue;
        d[child] = d[vartex] + 1;
        dfs(child, vartex);
        h[vartex] = max(h[vartex] , h[child] + 1);
    }
}
void reset(int n) {
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
        g[i].clear();
        h[i] = 0;
    }
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
    int mx_depth = -1;
    int max_d_node;

    for(int i = 1; i <= n; i++)
    {
        if(mx_depth < d[i])
        {
            mx_depth = d[i];
            max_d_node = i;
        }
        d[i] = 0;
    }
    dfs(max_d_node);
    mx_depth = -1;
    for(int i = 1; i <= n; i++){
        if(mx_depth < d[i]){
            mx_depth = d[i];
        }
    }
    cout << mx_depth << endl;
}

int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}