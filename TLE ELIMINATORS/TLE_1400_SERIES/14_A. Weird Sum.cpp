#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> pos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            pos[x].push_back({i, j});
        }
    }

    ll ans = 0;

    for (auto &entry : pos)
    {
        auto &v = entry.second;
        int k = v.size();
        if (k <= 1)
            continue;

        vector<ll> rows(k), cols(k);
        for (int i = 0; i < k; i++)
        {
            rows[i] = v[i].first;
            cols[i] = v[i].second;
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        ll prefix = 0;
        for (int i = 0; i < k; i++)
        {
            ans += rows[i] * i - prefix;
            prefix += rows[i];
        }

        prefix = 0;
        for (int i = 0; i < k; i++)
        {
            ans += cols[i] * i - prefix;
            prefix += cols[i];
        }
    }

    cout << ans << '\n';
    return 0;
}
