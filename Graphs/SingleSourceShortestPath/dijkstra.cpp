/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(int src, vector<vector<pair<int, ll>>> &graph)
{

    int n = graph.size();
    vector<ll> dist(n, LLONG_MAX);
    vector<int> parent(n, -1);
    dist[src] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    pq.push({0, src});

    while (!pq.empty())
    {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u])
        {
            int v = edge.first;
            ll wt = edge.second;

            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}