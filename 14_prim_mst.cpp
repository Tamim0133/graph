/*
(1) pick a root node
(2) repeatedly add the min edge
(3) that connects an unvisited node to a visited node
*/
#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, int E, vector<pair<int, int>> adj[])
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, false);
    int res = 0;

    pq.push({0, 0}); // 0 is the root node here

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if (visited[u] == true)
            continue;

        res += wt;
        visited[u] = true;

        // if I need to print the mst i can add it here .

        for (auto [node, weight] : adj[u])
        {
            if (visited[node] == false)
            {
                pq.push({node, weight});
            }
        }
    }

    return res;
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    vector<pair<int, int>> adj_list[nodes + 10];

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    cout << spanningTree(nodes, edges, adj_list) << endl;

    return 0;
}
