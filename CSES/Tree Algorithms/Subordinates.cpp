/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
 *CSES Problem Set-Subordinates
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> adj;
vector<ll> ans;

ll dfs(ll x)
{
    ll sz = 1;

    for (ll child : adj[x])
    {

        sz += dfs(child);
    }

    ans[x] = sz - 1;
    return sz;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    adj.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        adj[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}