#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void solve()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k))
        return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> ans(n, 0);

    for (int l = 0; l < n; ++l)
    {
        vector<long long> cur;
        for (int r = l; r < n; ++r)
        {
            int len = r - l;
            if (len >= k)
                break;
            cur.push_back(a[r]);

            vector<long long> b = cur;
            sort(b.rbegin(), b.rend());
            int sz = b.size();
            vector<long long> ps(sz + 1, 0);
            for (int i = 0; i < sz; ++i)
                ps[i + 1] = ps[i] + b[i];

            for (int s = l; s <= r; ++s)
            {
                int d = len + min(s - l, r - s);
                long long m = k - d;
                if (m > 0)
                {
                    int take = min((long long)sz, m);
                    ans[s] = max(ans[s], ps[take]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
