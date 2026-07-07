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
        ll n, k;
        cin >> n >> k;

        if (k >= n)
        {
            cout << n << "\n";
            continue;
        }

        ll ans = 0;
        ll i = 1;

        while (n >= k * i)
        {
            n -= k * i;
            i *= 2;
            ans += k;
        }

        if (n > 0)
        {
            while (n >= i)
            {
                n -= i;
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}