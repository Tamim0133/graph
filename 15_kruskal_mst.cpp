/*
(1) Find the min edge
(2) if it doesn't create a cycle add it
*/
#include <bits/stdc++.h>
using namespace std;

// DSU TEMPLATE
//===================
const int N = 5e5 + 9;

struct DSU
{
	vector<int> par, rnk, sz;
	int c;
	DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n)
	{
		for (int i = 1; i <= n; ++i)
			par[i] = i;
	}
	int find(int i) // "i" er set er parent
	{
		return (par[i] == i ? i : (par[i] = find(par[i])));
	}
	bool same(int i, int j) // "i" and "j" ki same set er  ki na
	{
		return find(i) == find(j);
	}
	int get_size(int i) // "i" je set er  , oi set er size koto
	{
		return sz[find(i)];
	}
	int count() // no of connected components
	{
		return c;
	}
	int merge(int i, int j) // Kuno set er root element er sathe sobai connected thakbe , so jekono ektar sathe baki gula connect kore dilei cholbe
	{
		if ((i = find(i)) == (j = find(j)))
			return -1;
		else
			--c;
		if (rnk[i] > rnk[j])
			swap(i, j);
		par[i] = j;
		sz[j] += sz[i];
		if (rnk[i] == rnk[j])
			rnk[j]++;
		return j;
	}
};

int kruskal(int nodes, int edges, vector<tuple<int, int, int>> edgelist)
{
	int ans = 0;
	DSU d(nodes + 1);
	sort(edgelist.begin(), edgelist.end());

	for (auto [w, u, v] : edgelist)
	{
		if (d.find(u) != d.find(v))
		{
			d.merge(u, v);
			ans += w;
		}
	}

	return ans;
}

int main()
{
	int nodes, edges;
	cin >> nodes >> edges;

	vector<tuple<int, int, int>> edgelist;

	for (int i = 0; i < edges; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edgelist.push_back({w, u, v});
	}

	cout << kruskal(nodes, edges, edgelist) << endl;
}

/*
4 5
0 1 10
1 3 15
2 3 4
2 0 6
0 3 5
*/