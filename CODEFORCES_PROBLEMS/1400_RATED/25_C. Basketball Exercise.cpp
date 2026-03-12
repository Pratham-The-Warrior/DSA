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

    int n;
    cin >> n;

    ll a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll dp1[n], dp2[n];

    dp1[0] = a[0];
    dp2[0] = b[0];

    for (int i = 1; i < n; i++)
    {
        dp1[i] = max(dp2[i - 1] + a[i], dp1[i - 1]);
        dp2[i] = max(dp1[i - 1] + b[i], dp2[i - 1]);
    }

    cout << max(dp1[n - 1], dp2[n - 1]) << endl;
}