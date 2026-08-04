/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/
/*
*CSES Problem Set
Message Route
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    just do bfs
    */
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n + 1, -1);

    vector<bool> vis(n + 1, false);

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
                parent[v] = u;
            }
        }
    }

    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;

    for (int i = n; i != -1; i = parent[i])
    {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (auto x : path)
    {
        cout << x << " ";
    }

    return 0;
}