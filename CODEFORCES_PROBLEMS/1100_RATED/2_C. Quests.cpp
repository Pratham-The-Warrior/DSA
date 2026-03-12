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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        ll sum_a = 0;
        int max_b = 0;
        ll ans = 0;

        int limit = min(n, k);
        for (int i = 0; i < limit; i++)
        {
            sum_a += a[i];
            max_b = max(max_b, b[i]);
            ll remaining = k - (i + 1);
            ll total = sum_a + remaining * 1LL * max_b;
            ans = max(ans, total);
        }

        cout << ans << endl;
    }

    return 0;
}
