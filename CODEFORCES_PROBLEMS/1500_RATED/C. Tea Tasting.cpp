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
        ll n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++)
            cin >> b[i];

        // Prefix sum of b
        vector<ll> pref(n);
        pref[0] = b[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + b[i];

        vector<ll> freq(n + 1, 0), rem(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            ll val = a[i];
            if (i > 0)
                val += pref[i - 1];

            // Find stopping index
            int idx = upper_bound(pref.begin(), pref.end(), val) - pref.begin();

            // Mark full coverage
            freq[i] += 1;
            freq[idx] -= 1;

            // Partial contribution
            if (idx < n)
            {
                ll used = (idx > 0 ? pref[idx - 1] : 0);
                rem[idx] += (val - used);
            }
        }

        // Build prefix for freq
        for (int i = 1; i < n; i++)
            freq[i] += freq[i - 1];

        // Compute result
        for (int i = 0; i < n; i++)
        {
            ll ans = freq[i] * b[i] + rem[i];
            cout << ans << " ";
        }
        cout << '\n';
    }

    return 0;
}