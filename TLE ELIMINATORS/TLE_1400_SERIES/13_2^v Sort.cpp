#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        k++;

        vector<ll> a(n);
        for (ll &x : a)
            cin >> x;

        // Edge case: window size 1 is always valid
        if (k == 1)
        {
            cout << n << "\n";
            continue;
        }

        vector<int> bad(n - 1, 0);
        for (ll i = 0; i + 1 < n; i++)
        {
            if (a[i + 1] * 2 <= a[i])
                bad[i] = 1;
        }

        ll ans = 0;
        ll badCount = 0;

        // First window of size k -> k-1 adjacent pairs
        for (ll i = 0; i < k - 1; i++)
            badCount += bad[i];

        if (badCount == 0)
            ans++;

        // Slide the window
        for (ll i = k - 1; i < n - 1; i++)
        {
            badCount -= bad[i - (k - 1)];
            badCount += bad[i];

            if (badCount == 0)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}
