#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int V = 5;

    vector<Edge> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}};

    vector<int> dist(V, INT_MAX);

    int source = 0;
    dist[source] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++)
    {

        for (auto e : edges)
        {

            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.w < dist[e.v])
            {

                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Detect negative cycle
    bool negativeCycle = false;

    for (auto e : edges)
    {

        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.w < dist[e.v])
        {

            negativeCycle = true;
        }
    }

    if (negativeCycle)
    {
        cout << "Negative Weight Cycle Exists\n";
    }
    else
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Distance to " << i
                 << " = " << dist[i] << endl;
        }
    }
}