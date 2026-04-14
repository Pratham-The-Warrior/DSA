#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> h(n), s(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<ll> dp(x + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= h[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x];

    return 0;
}

//!----------------------------------------------------------------!//

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll n, x;
//     cin >> n >> x;

//     vector<ll> h(n), s(n);

//     for (int i = 0; i < n; i++)
//         cin >> h[i]; // weight

//     for (int i = 0; i < n; i++)
//         cin >> s[i]; // value

//     // dp[i][j] = max value using first i items and capacity j
//     vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= x; j++)
//         {
//             dp[i][j] = dp[i - 1][j];

//             if (j >= h[i - 1])
//             {
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
//             }
//         }
//     }
//     cout << dp[n][x];
//     return 0;
// }