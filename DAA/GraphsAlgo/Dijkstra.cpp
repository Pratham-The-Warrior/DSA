/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void dijkstra(int source, const vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int d = p.first;
        int u = p.second;
        if (d > dist[u])
            continue;

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "From junction " << source << ": ";
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
        }

        for (int i = 0; i < n; ++i)
        {
            dijkstra(i, graph);
        }
        cout << endl;
    }

    return 0;
}