/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < n; j++)
    {
        for (ll i = c[j]; i <= x; i++)
        {

            dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
    }

    cout << dp[x];
    return 0;
}