/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
  A connected graph with n vertices and n edges is known as a unicyclic graph.
  This means the graph contains exactly one cycle, and attached to the vertices
  of this cycle are various trees (or "branches").
  **kinda like a benzene hydronkarbon ahh...

  A simple path is a route between two vertices where
  you never visit the same vertex twice

  In a normal graph number of simple paths would be nC2
  But in unicyclic there are two possibilities for each node:-
       1->if both nodes are in same branch of cycle
       2->if both nodes are not in same branch (i.e two ways to reach are there)
          Go clockwise around the cycle.
          Go counter-clockwise around the cycle.

          or

   Total paths betweenn two nodes will be n*(n-1)
   for each subtree we will have to subtract



*/

void dfsFindCycle(int u, int parent, vector<vector<int>> &adj, vector<int> &parentArr, vector<bool> &visited, vector<bool> &isOnCycle, vector<int> &cycle, bool &found)
{
    if (found)
        return;

    visited[u] = true;

    parentArr[u] = parent;

    for (int v : adj[u])
    {
        if (found)
            return;

        if (!visited[v])
        {
            dfsFindCycle(v, u, adj, parentArr, visited, isOnCycle, cycle, found);
        }
        else if (v != parent)
        {
            found = true; // cycle exist between u and v
            int curr = u;
            while (curr != v)
            { // backtrack and store cycle nodes
                isOnCycle[curr] = true;
                cycle.push_back(curr);
                curr = parentArr[curr];
            }
            isOnCycle[v] = true;
            cycle.push_back(v);
            return;
        }
    }
}

int dfsSubtree(int u, int parent, vector<vector<int>> &adj, vector<bool> &isOnCycle, vector<int> &subtree)
{

    subtree[u] = 1; // count of each node

    for (int v : adj[u])
    {
        if (v != parent && !isOnCycle[v])
        {
            subtree[u] += dfsSubtree(v, u, adj, isOnCycle, subtree);
        }
    }
    return subtree[u];
}

int main()
{
    // your code goes here
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        vector<int> parentArr(n + 1, -1); // to get parent of node basically helper to get cycle nodes
        vector<int> subtree(n + 1, 0);
        vector<bool> visited(n + 1, false);
        vector<bool> isOnCycle(n + 1, false);
        vector<int> cycle;

        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool found = false;

        dfsFindCycle(1, -1, adj, parentArr, visited, isOnCycle, cycle, found); // get unicycle nodes

        ll ans = 1LL * n * (n - 1); // max ways to choose paths between two nodes
        // every pair has two paths assume

        for (int u : cycle)
        { // iterate over cycle
            dfsSubtree(u, -1, adj, isOnCycle, subtree);
            ll size = subtree[u];
            ans -= (size * (size - 1)) / 2; // subtree nodes will have only one path as no cycle
        }

        cout << ans << endl;
    }
}