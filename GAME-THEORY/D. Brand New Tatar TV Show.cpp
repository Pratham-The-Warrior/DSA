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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        map<ll, ll, greater<ll>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[a[i]]++;
        }

        bool win = false;
        vector<pair<ll, ll>> v(mp.begin(), mp.end());

        for (int i = 0; i < v.size(); i++)
        {
            ll mx = v[i].first;
            ll cnt = v[i].second;

            if (cnt % 2 == 0)
            {
                // Case A: If the maximum has
                // an even count, Arseniy can force Egor to win
                win = true;
                break;
            }

            if (i + 1 < v.size())
            {
                ll mx2 = v[i + 1].first;

                if (mx - mx2 <= k)
                {
                    // since cnt is odd
                    // If the gap to the next element is <= k,
                    // Arseniy can take mx2, forcing Egor to win via mx
                    win = true;
                    break;
                }
            }
            else
            {
                // No second maximum exists and count is odd -> Egor loses
                win = false;
                break;
            }

            // only case remaining is gap>k and cnt is odd , we loop
        }

        cout << (win ? "YES" : "NO") << "\n";
    }

    return 0;
}