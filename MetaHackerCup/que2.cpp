/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc)
    {
        int N;
        cin >> N;
        vector<long long> A(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> A[i];

        vector<array<long long, 3>> edges;

        // Ground (node 0) to platform i
        for (int i = 1; i <= N; ++i)
            edges.push_back({A[i], 0, i});

        // Between adjacent platforms
        for (int i = 1; i < N; ++i)
            edges.push_back({llabs(A[i] - A[i + 1]), i, i + 1});

        sort(edges.begin(), edges.end());

        DSU dsu(N + 1);
        long long ans = 0;
        int connected = 0;

        for (auto &e : edges)
        {
            long long w = e[0];
            int u = e[1], v = e[2];
            if (dsu.unite(u, v))
            {
                ans = max(ans, w);
                connected++;
                if (connected == N)
                    break;
            }
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}
