/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;      // mark current node as visited
    ls.push_back(node); // add node to traversal list

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<int> adj[n + 1]; // adjacency list

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph; remove for directed
    }

    int vis[n + 1] = {0};
    vector<int> dfsResult;

    // Perform DFS for every unvisited node (for disconnected graphs)
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, dfsResult);
        }
    }

    cout << "\nDFS Traversal: ";
    for (auto node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
