/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

/***********************  DSU FOR KRUSKAL  *************************/
struct DSU
{
    vector<int> parent, rankv;
    DSU(int n)
    {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rankv[a] < rankv[b])
            swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b])
            rankv[a]++;
        return true;
    }
};

/**************************** KRUSKAL *******************************/
struct Edge
{
    int u, v, w;
};

int kruskalMST(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b)
         { return a.w < b.w; });

    DSU dsu(n);
    int totalWeight = 0;

    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            totalWeight += e.w;
        }
    }
    return totalWeight;
}

/***************************** PRIM ********************************/
int primMST(int n, vector<vector<pair<int, int>>> &adj)
{
    vector<bool> inMST(n, false);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    pq.push({0, 0}); // (weight, node)
    int totalWeight = 0;

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int w = top.first;
        int u = top.second;

        if (inMST[u])
            continue;
        inMST[u] = true;

        totalWeight += w;

        for (auto &p : adj[u])
        {
            int v = p.first;
            int w2 = p.second;
            if (!inMST[v])
                pq.push({w2, v});
        }
    }
    return totalWeight;
}

/***************************** MAIN ********************************/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example Input Format:
    // n m
    // u v w (m times)
    //
    // Feel free to replace or integrate into your own logic.

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Kruskal MST Weight: " << kruskalMST(n, edges) << "\n";
    cout << "Prim MST Weight: " << primMST(n, adj) << "\n";

    return 0;
}
