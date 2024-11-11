
// vector<vector<int>> adj;  // adjacency list representation
// int n; // number of nodes
// int s; // source vertex

// queue<int> q;
// vector<bool> used(n);
// vector<int> d(n), p(n); // depth mane level

// q.push(s);
// used[s] = true;
// p[s] = -1;
// while (!q.empty()) {
//     int v = q.front();
//     q.pop();
//     for (int u : adj[v]) {
//         if (!used[u]) {
//             used[u] = true;
//             q.push(u);
//             d[u] = d[v] + 1;
//             p[u] = v;
//         }
//     }
// }

// void reset(int n) {
//     // Clear the adjacency list for all nodes
//     for (int i = 0; i < n; i++) {
//         adj[i].clear();
//     }
    
//     // Reset the used, depth (d), and parent (p) vectors
//     used.assign(n, false);  // Reset 'used' to all false
//     d.assign(n, 0);         // Reset 'd' to all zeros
//     p.assign(n, -1);        // Reset 'p' to all -1 (no parent)
// }
