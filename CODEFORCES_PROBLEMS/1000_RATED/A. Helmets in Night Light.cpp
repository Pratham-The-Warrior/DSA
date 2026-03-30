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

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<pair<ll, ll>> pairs(n);

        for (ll i = 0; i < n; i++)
        {
            pairs[i] = {b[i], a[i]};
        }

        sort(pairs.begin(), pairs.end());

        ll ans = 0;
        ll ct = n - 1;

        ll j = 0;

        while (j < n && ct >= 0)
        {
            if (p <= pairs[j].first)
            {
                break;
            }

            ll take = min(pairs[j].second, ct);
            ct -= take;

            if (take < 0)
                break;

            ans = ans + take * pairs[j].first;
            j++;
        }

        if (ct > 0)
        {
            ans = ans + ct * p;
        }

        cout << ans + p << endl;
    }

    return 0;
}