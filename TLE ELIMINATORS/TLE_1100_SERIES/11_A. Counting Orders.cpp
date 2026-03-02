/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 1;

    for (int i = 0; i < n; i++)
    {
        // lower_bound finds the first element in 'b' that is >= a[i].
        // By subtracting b.begin(), we get the exact count of elements strictly less than a[i].
        ll valid_b_count = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

        // Subtract 'i' because 'i' smaller elements from 'a' have already claimed a valid 'b'
        ll current_ways = valid_b_count - i;
        if (current_ways <= 0)
        {
            ans = 0;
            break;
        }
        ans = (ans * current_ways) % mod;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}