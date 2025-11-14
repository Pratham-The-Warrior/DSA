/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, const vector<vector<int>> &graph, const vector<int> &path, int pos)
{
    // Check if this vertex is adjacent to the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex is already included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool findHamiltonianCycle(const vector<vector<int>> &graph, vector<int> &path, int pos)
{
    int V = graph.size();

    // Base case: all vertices included, check if last connects to first
    if (pos == V)
    {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try next vertex
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (findHamiltonianCycle(graph, path, pos + 1))
                return true;

            path[pos] = -1; // backtrack
        }
    }

    return false;
}

int main()
{
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    vector<int> path(V, -1);
    path[0] = 0; // start at vertex 0

    if (findHamiltonianCycle(graph, path, 1))
    {
        cout << "\nHamiltonian Cycle found: ";
        for (int v : path)
            cout << v << " ";
        cout << path[0] << endl; // complete the cycle
    }
    else
    {
        cout << "\nNo Hamiltonian Cycle exists.\n";
    }

    return 0;
}
