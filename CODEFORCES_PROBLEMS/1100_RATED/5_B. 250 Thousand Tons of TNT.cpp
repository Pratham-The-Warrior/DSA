/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<long long> get_factors(long long n)
{
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (n / i != i)
                res.push_back(n / i);
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Prefix sum for fast block sum
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];

        vector<ll> factors = get_factors(n);

        ll ans = 0;

        for (auto k : factors)
        {
            if (n % k != 0)
                continue;

            ll mx = LLONG_MIN;
            ll mn = LLONG_MAX;

            for (int i = 0; i < n; i += k)
            {
                ll block_sum = pref[i + k] - pref[i];
                mx = max(mx, block_sum);
                mn = min(mn, block_sum);
            }

            ans = max(ans, mx - mn);
        }

        cout << ans << endl;
    }

    return 0;
}