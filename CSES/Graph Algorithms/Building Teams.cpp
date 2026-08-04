/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/
/*
 *CSES Problem Set Building Teams
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    seems like bipartite graph
    color them then blue color will be 1 and red color will be 2
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

    vector<int> color(n + 1, 0);
    bool possible = true;

    for (int i = 1; i <= n; i++)
    {
        if (color[i] != 0)
        {
            continue;
        }
        queue<int> q;
        q.push(i);
        color[i] = 1;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto nxt : adj[node])
            {
                if (color[nxt] == 0)
                {
                    color[nxt] = 3 - color[node];
                    // whichever are connected to this node give them 2
                    q.push(nxt);
                }
                else if (color[nxt] == color[node])
                {
                    possible = false;
                    // not possible bipartite
                }
            }
        }
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << color[i] << " ";
    }

    return 0;
}