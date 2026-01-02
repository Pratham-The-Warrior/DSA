/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (k > 2)
        {
            cout << 0 << '\n';
            continue;
        }

        sort(a.begin(), a.end());

        long long ans = a[0];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long x = a[i] - a[j];
                ans = min(ans, x);

                if (k == 2)
                {
                    // Find closest element to x using lower_bound
                    auto it = lower_bound(a.begin(), a.end(), x);
                    long long val = LLONG_MAX;
                    if (it != a.end())
                        val = min(val, *it - x);
                    if (it != a.begin())
                        val = min(val, x - *(it - 1));
                    ans = min(ans, val);
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
