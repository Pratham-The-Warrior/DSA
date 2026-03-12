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

    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];

        ll total = pref[n];
        ll ans = 0;

        for (ll i = 0; i <= k; i++)
        {
            if (2 * i > n) // edge cases
                continue;
            if (k - i > n)
                continue;
            if (2 * i + (k - i) > n)
                continue;

            ll remove_small = pref[2 * i];
            ll remove_large = pref[n] - pref[n - (k - i)]; // acting as suffix sum

            ll remaining = total - remove_small - remove_large;

            ans = max(ans, remaining);
        }

        cout << ans << endl;
    }

    return 0;
}