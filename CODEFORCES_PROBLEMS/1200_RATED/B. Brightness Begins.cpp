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

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        ll k;
        cin >> k;

        ll l = 1, h = 2e18;

        // n - sqrtn == k
        ll ans = 0;
        while (l <= h)
        {
            ll mid = l + (h - l) / 2;

            ll sq = sqrtl(mid);

            ll on = mid - sq;

            if (on >= k)
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}