/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M      *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll k, const vector<ll> &a, ll n)
{
    ll need = 0, extra = 0;

    unordered_map<ll, ll> mp;
    for (ll x : a)
        mp[x]++;

    for (auto &x : mp)
    {
        ll ct = x.second;
        if (k >= ct)
            extra += (k - ct) / 2;
        else
            need += ct - k;
    }

    ll zero = n - mp.size();
    extra += zero * (k / 2);

    return need <= extra;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<ll> a(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> a[i];
        }

        ll l = 0, h = m, ans = -1;

        while (l <= h)
        {
            ll mid = (l + h) / 2;

            if (check(mid, a, n))
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
