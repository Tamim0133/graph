// https://codeforces.com/problemset/problem/329/B
#include <bits/stdc++.h>
using namespace std;

const int N = 2002;
const int inf = 1e9;

int maze[N][N], visited[N][N];
int level[N][N];

int n, m;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;
    if (maze[x][y] == -1)
    {
        return false;
    }
    return true;
}

void bfs(pair<int, int> src)
{

    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    q.push(src);

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if (is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    pair<int, int> src, amrPosition;
    vector<pair<int, int>> breeders;
    
    // Reset Level or Distance
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            level[i][j] = inf;
            visited[i][j] = 0;
        }
    }
    vector<string>v(n);
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        v[i] = input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == 'T')
            {
                maze[i][j] = -1;
            }
            else if (input[j] == 'E')
            {
                src = {i, j};
            }
            else if (input[j] == 'S')
            {
                amrPosition = {i, j};
            }
            else if(input[j] != '0')
            {
                breeders.push_back({i,j});
            }
        }
    }


    bfs(src);

    int amrMinDis = level[amrPosition.first][amrPosition.second];
    // cout << amrMinDis << endl;
    int fightKoyJonerSatheKoraLagbe = 0;

    for(auto [i,j] : breeders)
    {
        int d = level[i][j];
        // cout << "d : " << d << endl;
        if(d <= amrMinDis) fightKoyJonerSatheKoraLagbe += v[i][j] - '0';
    }

    cout << fightKoyJonerSatheKoraLagbe << endl;

    

    return 0;
}