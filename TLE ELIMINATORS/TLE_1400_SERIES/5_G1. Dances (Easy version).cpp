#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n), b(n);

        a[0] = 1;
        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        int ct = 0;

        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(b.begin(), b.end(), a[i]);
            if (it != b.end())
            {
                ct += 2;
                b.erase(it); // use element once
            }
        }

        int ans = (2 * n - ct) / 2;
        cout << ans << "\n";
    }

    return 0;
}
