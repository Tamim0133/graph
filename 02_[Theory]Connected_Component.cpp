#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
// vector<vector<int>> cc;
// vector<int> curr_cc;
int vis[N];

void dfs(int vartex)
{
    vis[vartex] = 1;
    // curr_cc.push_back(vartex);
    for(int child : g[vartex])
    {
        if(!vis[child]) dfs(child);
    }
}


void solve()
{
    int n , e; cin >> n >> e;

    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        g[i].clear();
    }
    // cc.clear();        
    // curr_cc.clear();

    for(int i = 0; i < e; i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i])
        {
            // curr_cc.clear();
            dfs(i);
            // cc.push_back(curr_cc);
            cnt++;
        }
    }
     // cout << "Number of connected components: " << cnt << endl;
    // for(const auto& component : cc) {
    //     for(int node : component) {
    //         cout << node << " ";
    //     }
    //     cout << endl;
    // }
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