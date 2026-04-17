/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM-STATEMENT
Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked them to add
edges to it in such a way, that the graph is still bipartite. Besides, after adding
these edges the graph should be simple (doesn't contain loops or multiple edges).
What is the maximum number of edges they can add?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<int> color;

/*
i have to make sure the graph componets stay bipartite
to be bipartite => no odd cycle so i can form even cycle => edges can be added if they help in making even cycle but
make sure the cyle is not of size == 2 as this will break the condition of one edge only between nodes
*/

/*
The maximum number of edges possible in any bipartite simple graph is A × B (complete bipartite graph)
Since you already have a tree, it already has n - 1 edges and is always bipartite. So:
For a fixed bipartition:
Let sizes be A and B
Answer max_new_edges=A⋅B−(n−1)
*/

// so i have to find A dn B

// coloring nodes
void dfs(int u, int c)
{
    color[u] = c;
    for (int v : adj[u])
    {
        if (color[v] == -1)
        {
            dfs(v, c ^ 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    adj.assign(n + 1, {});
    color.assign(n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0); // coloring 0

    int ans = 0;

    int A = 0, B = 0;

    for (auto c : color)
    {
        if (c == 1)
            A++;
        else if (c == 0)
            B++;
    }

    cout << 1LL * A * B - n + 1;

    return 0;
}