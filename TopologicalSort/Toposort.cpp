/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st)
{

    vis[u] = true;

    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, adj, vis, st);
        }
    }
    st.push(u);
}

vector<int> topoSort(int V, vector<vector<int>> &adj)
{
    vector<bool> vis(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topo;

    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
    }

    return 0;
}