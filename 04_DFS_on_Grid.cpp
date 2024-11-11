#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const int N = 1e3 + 5;
int n, m;

bool vis[N][N] = {0};

int dx[] = {0, 0, -1, 1, 1, 1, -1 , -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1,  -1};


void dfs(int x, int y)
{
    vis[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx, ny;

        nx = x + dx[i];
        ny = y + dy[i];

        if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1 && !vis[nx][ny])
        {
             dfs(nx, ny);
        }
    }
}

void solve()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!vis[i][j])
            {
                dfs(i,j);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}