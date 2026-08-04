/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> a(n);
    ll total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        total += a[i];
    }

    ll ans = LLONG_MAX;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        ll sum1 = 0;

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                sum1 += a[i];
            }
        }

        ll sum2 = total - sum1;

        ans = min(ans, llabs(sum1 - sum2));
    }

    cout << ans;

    return 0;
}