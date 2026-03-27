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
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        vector<ll> pref(n);
        pref[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + a[i];
        }

        for (int i = 0; i < q; i++)
        {
            ll l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            ll temp = pref[r] - (l > 0 ? pref[l - 1] : 0);
            ll total = sum - temp;
            total += k * (r - l + 1);
            if (total % 2 == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}