#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*solution :-> https://www.youtube.com/watch?v=teyxFYAmiQQ*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<ll, ll> mp;

    mp[1] = 1;

    for (ll i = 2; i <= (ll)1e18; i <<= 1)
    {
        mp[i] = mp[i >> 1] * 2 + 1;
    }

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 0;
        ll bit = 0;

        while (n > 0)
        { // this gives power of 2 of any number
            if (n & 1)
            {
                ans += mp[1LL << bit];
            }
            bit++;
            n >>= 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
