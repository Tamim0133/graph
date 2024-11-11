#include <bits/stdc++.h>
using namespace std;
#define int long long int
long long mod = 1e9 + 7;
int n;
vector<int> val;
vector<vector<int>> components;

class Solution
{
private:
    int scc = 0;
    void dfs(int node, vector<int> &vis, vector<int> adj[],
             stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1;
        components[scc].push_back(node);
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V + 1, 0);
        stack<int> st;
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        vector<int> adjT[V + 1];
        for (int i = 1; i <= V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

int32_t main()
{

    cin >> n;
    val.resize(n + 1);
    components.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    vector<int> adj[n + 1];

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    int ans = obj.kosaraju(n, adj);
    // cout << "The number of strongly connected components is: " << ans << endl;

    int cost = 0;
    int ans1 = 1;
    for (int i = 1; i <= n; i++)
    {
        if (components[i].size())
        {
            int add = INT64_MAX;
            int cnt = 0;
            for (auto ele : components[i])
            {
                add = min(add, val[ele]);
            }

            cost = (cost + add);
            for (auto ele : components[i])
            {
                if (val[ele] == add)
                    cnt++;
            }
            ans1 = (ans1 % mod * cnt % mod) % mod;
        }
    }
    cout << cost << " " << ans1 << endl;
    return 0;
}
