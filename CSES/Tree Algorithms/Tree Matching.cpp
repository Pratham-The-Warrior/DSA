/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/
/*
 *CSES Problem Set-Tree Matching
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;

vector<int> adj[N];
int dp[N][2];
// dp[u][0] = maximum matching in subtree of u
//            when u is NOT matched with any child
//
// dp[u][1] = maximum matching in subtree of u
//            when u IS matched with one of its children

void dfs(int u, int par)
{

    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }

        dfs(v, u);
    }

    // case 1
    // u is not matched

    dp[u][0] = 0; // initial value

    for (auto v : adj[u])
    {
        if (v == par)
            continue;
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }

    // case 2
    // u is matched
    dp[u][1] = 0;
    for (auto v : adj[u])
    {
        if (v == par)
        {
            continue;
        }

        int candidate = dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1;

        dp[u][1] = max(dp[u][1], candidate);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dp => What is the maximum matching inside the subtree rooted at 2?

    // there are only 2 possibilities
    /*
    Case 1: Don't match 2 with any child.
    Case 2: Match 2 with one child.


    */

    dfs(1, 0); // initial node 1 and parent of 1 is 0 i.e no one

    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}