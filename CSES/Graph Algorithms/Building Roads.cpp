/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/
/*
 *CSES Problem Set-Building Roads
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int node)
{
    vis[node] = true;
    for (auto nxt : adj[node])
    {
        if (!vis[nxt])
        {
            dfs(nxt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // there is atmost one road beteween two cities
    // i think if the cities are in same connected compinent then we can absoulutely reach it
    // only if they are in separte components we will need to add a new road
    // so i guess answer simply becmes
    // number of componenets-1 roads need to be created

    adj.resize(n + 1);
    vis.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> reps;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            reps.push_back(i);
            dfs(i);
        }
    }

    cout << reps.size() - 1 << "\n";

    for (int i = 1; i < reps.size(); i++)
    {
        cout << reps[i - 1] << " " << reps[i] << "\n";
    }

    return 0;
}