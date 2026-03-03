/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> adj;
vector<int> color;
vector<bool> visited;

vector<pair<int, int>> edges;

bool dfs(int u)
{
    visited[u] = true;

    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            color[v] = 1 - color[u];
            if (!dfs(v))
                return false;
        }
        else if (color[v] == color[u])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* A graph is bipartite if:

You can split vertices into 2 sets

Every edge connects one set to the other

No edge connects vertices inside the same set

If the graph has an odd cycle, it is NOT bipartite.

a->b<-c  ||  a<-b->c  ==>  there are two groups of vertices and every edge must connect

*****this is the exact conditon of bipartite graph*****
    */
    cin >> n >> m;

    adj.resize(n + 1);
    color.assign(n + 1, -1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    color[1] = 0;

    if (!dfs(1))
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;

        if (color[u] == 0)
        {
            cout << "0";
        }
        else
        {
            cout << "1";
        }
    }
    cout << endl;

    return 0;
}