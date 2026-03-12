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
        long long n;
        cin >> n;
        vector<long long> a(n + 1);
        for (long long i = 1; i <= n; i++)
            cin >> a[i];

        ll ans = 0;
        vector<ll> dp(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                if (a[j] > a[i])
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << endl;
    }

    return 0;
}
