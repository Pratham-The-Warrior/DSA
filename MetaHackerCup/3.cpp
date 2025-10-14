#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    for (int tc = 1; tc <= T; ++tc)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        vector<int> cnt(N + 2, 0);
        for (int v : A)
            ++cnt[v];
        vector<int> g(N + 2, 0);
        for (int v = 1; v <= N; ++v)
            g[v] = cnt[v] - cnt[v + 1];

        vector<int> ks, pos;
        vector<int> seen(N + 2, 0);
        int stamp = 1, start = 0, curmax = 0, uniq = 0, p1 = -1;
        for (int i = 0; i < N; ++i)
        {
            int v = A[i];
            if (seen[v] != stamp)
            {
                seen[v] = stamp;
                ++uniq;
            }
            curmax = max(curmax, v);
            if (v == 1)
                p1 = i - start + 1;
            int len = i - start + 1;
            if (curmax == len && uniq == curmax && curmax > 0 && g[curmax] > 0)
            {
                ks.push_back(curmax);
                pos.push_back(p1);
                --g[curmax];
                ++stamp;
                start = i + 1;
                curmax = uniq = 0;
                p1 = -1;
            }
        }

        int m = ks.size();
        vector<ll> x(m, 0);
        vector<int> s(m, 0);
        for (int j = 0; j < m; ++j)
        {
            int k = ks[j], p = pos[j];
            s[j] = (k - p + 1) % k;
        }
        if (m)
        {
            x[m - 1] = s[m - 1];
            for (int j = m - 2; j >= 0; --j)
            {
                int k = ks[j];
                ll rem = x[j + 1] % k;
                int delta = (int)((s[j] - rem) % k);
                if (delta < 0)
                    delta += k;
                x[j] = x[j + 1] + delta;
            }
        }

        ll totalOps = m + (m ? x[0] : 0);
        cout << "Case #" << tc << ": " << totalOps << "\n";
        for (int j = 0; j < m; ++j)
        {
            cout << "1 " << ks[j] << "\n";
            ll after = (j + 1 < m ? x[j + 1] : 0);
            ll times = x[j] - after;
            for (ll t = 0; t < times; ++t)
                cout << "2\n";
        }
    }
    return 0;
}
