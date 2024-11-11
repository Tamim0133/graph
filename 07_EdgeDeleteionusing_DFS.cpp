#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
/*
Given Q queries, Q <= 1e5
    in each query given V,
    print subtree sum of V and number of even numbers in subtree of V
*/
vector<int> g[N];
int d[N], h[N];
int subtree_sum[N]; // subtree_sum[i] => i node er subtree er sum koto
int even_cnt[N]; // even_cnt[i] => i node er subtree e even element koyta

void dfs(int vartex, int par = 0){
    subtree_sum[vartex] += vartex;
    even_cnt[vartex] += (vartex % 2 == 0);
    for(int child : g[vartex])
    {
        if(child == par) continue;
        d[child] = d[vartex] + 1;
        dfs(child, vartex);
        h[vartex] = max(h[vartex] , h[child] + 1);

        subtree_sum[vartex] +=  subtree_sum[child];
        even_cnt[vartex] +=  even_cnt[child];
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
    {
        cout << i << " sum :" << subtree_sum[i] << endl;
    }
    
    int ans = 0;
    for(int i = 2; i <= n; i++){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = part1 * part2;
    }

    cout << ans << endl;
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