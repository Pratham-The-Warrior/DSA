/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
to get max product i think the paths must be largest path * second largest path
*but second largest paths can`t have any node of largest path
*n citues with n-1 edges is a fuckin tree
*so get two max paths

*/

vector<vector<int>> adj(205);

int max_d;

int get_diameter(int u, int p, int block)
{
    int h1 = 0, h2 = 0;

    for (auto v : adj[u])
    {
        if (v == p || v == block)
            continue;
        int h = get_diameter(v, u, block) + 1;

        if (h > h1)
        {
            h2 = h1;
            h1 = h;
        }
        else if (h > h2)
        {
            h2 = h;
        }
    }
    max_d = max(max_d, h1 + h2);
    return h1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> edges;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    int best_profit = 0;

    for (auto e : edges)
    {
        max_d = 0;
        get_diameter(e.first, 0, e.second); // blocking e.second
        int d1 = max_d;
        max_d = 0;
        get_diameter(e.second, 0, e.first);
        int d2 = max_d;
        best_profit = max(best_profit, d1 * d2);
    }
    cout << best_profit;
    return 0;
}