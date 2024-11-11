#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];

/*
    
(4) => ↑↓
        2 <= v (১)
(৩) => ↑↓ <= (২)
      /|\
    3  4  5

    void dfs(int vartex)
    {
        ১। একটা ভারটেক্স এ পৌঁছানোর পরে কিছু করতে চাই
        vis[vartex] = true;
        for(int child : g[vartex])
        {
            ২। নিচে চাইল্ড এ যাওয়ার আগে কিছু করতে চাই
            if(!vis[child]) dfs(child);
            ৩। চাইল্ড থেকে উপরে ব্যাক করার পরে কিছু করতে চাই
        }
        ৪। ভারটেক্স থেকে উপরে ব্যাক করার পরে  কিছু করতে চাই
    }

*/
void dfs(int vartex)
{
    vis[vartex] = true;
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

    for(int i = 0; i < e; i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
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