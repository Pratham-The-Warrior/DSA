/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 *Data strutures used :-
 *priority_queue<Type> pq;
 *priority_queue<Type, Container, Comparator>
 *push(x)	Insert element	O(log n)
 *pop()	Remove top element	O(log n)
 *top()	Access top element	O(1)
 *empty()	Check if empty	O(1)
 *size()	Number of elements	O(1)
 */

void dijkstra(int source, vector<vector<pair<int, ll>>> &graph)
{
    int n = graph.size();
    vector<ll> dist(n, LLONG_MAX); // FIXED
    vector<int> parent(n, -1);
    dist[source] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    pq.push({0, source});

    while (!pq.empty())
    {
        pair<ll, int> p = pq.top();
        pq.pop();
        ll d = p.first; // FIXED
        int u = p.second;
        if (d > dist[u])
        {
            continue;
        }

        for (auto edge : graph[u])
        {
            int v = edge.first;
            ll w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    if (dist[n - 1] == LLONG_MAX)
    {
        cout << -1;
        return;
    }

    vector<int> path;

    for (int i = n - 1; i != -1; i = parent[i])
    {
        path.push_back(i + 1);
    }

    reverse(path.begin(), path.end());

    for (auto p : path)
    {
        cout << p << " ";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[v].push_back({u, w});
        graph[u].push_back({v, w});
    }

    dijkstra(0, graph);

    return 0;
}