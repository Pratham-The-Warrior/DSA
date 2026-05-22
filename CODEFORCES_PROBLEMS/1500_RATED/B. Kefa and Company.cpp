/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/****https://codeforces.com/contest/580/problem/B***/

const int MAXN = 100005;
int n, m;
int cats[MAXN];
vector<int> graph[MAXN];
bool visited[MAXN];

int dfs(int node, int next)
{
    visited[node] = true;

    if (cats[node] == 1)
    {
        next++;
    }
    else
    {
        next = 0;
    }

    if (next > m)
    {
        return 0;
    }

    if (node != 1 && graph[node].size() == 1)
    {
        return 1;
    }

    int ct = 0;
    for (auto ngh : graph[node])
    {
        if (!visited[ngh])
        {
            ct += dfs(ngh, next);
        }
    }
    return ct; // no of restaturants
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }

    // adjacency list
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << dfs(1, 0) << endl;

    return 0;
}