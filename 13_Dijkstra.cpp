// input -> a weighted graph and a source
// ouput -> distance of all nodes from the source

/*
u -> v

if d[u] + c(u, v) < d[v]:
    d[v] = d[u] + c(u, v)

*/

// space complexity -> O(m)
// time complexity ===> O(m log n)

// - create a distance array "d" : d[src]= 0 , d[others] = INF
// - create a visited array and mark all nodes as unvisited
// - take an empty reverse priority_queue "pq"
// - pq.push({0, src})

// - while the priority_queue is not empty: -> O(E)
//     - {head_distance, head} = pq.front()
//     - pq.pop()
//     - if visited[head] == 1: ignore
//     - visited[head] = 1
//     - for all adj_node of head: -> O(E)
//         - if d[head] + c(head, adj_node) < d[adj_node]:
//             - d[adj_node] = d[head] + c(head, adj_node)
//             - pq.push({ d[adj_node], adj_node }); -> O(log E)

// - ouput array "d"

//  O(n) + O(E log E) + O(E log E)
//  -> O(|E| log |E|)
//  -> O(|E| log |V^2|)
//  -> O(2|E| log |V|)
//  -> O(|E| log |V|)   [base 2]

// https://codeforces.com/problemset/problem/20/C
// n -> 10^5
// m -> 10^5

// max_w -> 10^6

// 10^6 * 10^5 -> 10^11
// O(ElogV)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];

int visited[N], parent[N];
int nodes, edges;

long long d[N];

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {

        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;

        if (visited[selected_node])
            continue;

        visited[selected_node] = 1;

        for (auto [adj_node, edge_cst] : adj_list[selected_node])
        {
            if (d[selected_node] + edge_cst < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cst;
                parent[adj_node] = selected_node;
                pq.push({-d[adj_node], adj_node});
            }
        }
    }
}

int main()
{

    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    // if (visited[nodes] == 0)
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }

    // int current_node = nodes;
    // vector<int> path;

    // while (true)
    // {
    //     path.push_back(current_node);
    //     if (current_node == src)
    //     {
    //         break;
    //     }
    //     current_node = parent[current_node];
    // }
    // reverse(path.begin(), path.end());

    // for (int node : path)
    // {
    //     cout << node << " ";
    // }
    // cout << endl;
}
