/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS on a graph
void bfs(int start, vector<vector<int>> &adj)
{
    int n = adj.size();             // number of nodes
    vector<bool> visited(n, false); // track visited nodes
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all adjacent nodes
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

int main()
{
    int n, m; // n = number of nodes, m = number of edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove if the graph is directed
    }

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    bfs(start, adj);

    return 0;
}

// time complexity of bfs = o(N)+o(2*Edges)