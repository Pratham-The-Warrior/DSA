/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Representation of infinity

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m; // n = number of vertices, m = number of edges

    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Initialize distances: distance to self is 0
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Read edges
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w; // if graph is undirected, also do dist[v][u] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print shortest distance matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
