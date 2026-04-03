/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ====================================
    i feel this is a single source shortest path problem
    i have to calculate shortest distnace between any node to starting node

    so i will first find the shortest distnace of each node from start
    then i will create a vector<int>ans(k) of which will store answer for each product
    i.e shhortest path to get a product to port city

    so we will iterate over product each city produces i.e vector a[i]
    then we will store the minimum value found for that crop
    i.e ans[i] = min(ans[i],dist[i]) we will iterate over all cities and choose the city
    that gives us smallest distance for that particular crop
     ====================================*/

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--; // 0 based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS from city 1
    vector<int> dist(n, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    // max distance per product
    vector<int> max_dist(k, 0);
    for (int i = 0; i < n; i++)
    {
        int prod = a[i] - 1; // indexing
        max_dist[prod] = max(max_dist[prod], dist[i]);
    }

    for (int i = 0; i < k; i++)
    {
        cout << max_dist[i] << " ";
    }
    cout << endl;

    return 0;
}