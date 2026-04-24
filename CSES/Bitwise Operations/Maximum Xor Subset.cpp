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
    // vector<ll> a(n);
    // // for (int i = 0; i < n; i++)
    // // {
    // //     cin >> a[i];
    // // }

    /*
    12 => 1100
    6  => 0110
    1  => 0001

    bit by bit check whether that bit can be set or not
    31-->0,

    */

    vector<ll> basis(62, 0);

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        for (int j = 60; j >= 0; j--)
        {
            if (!(x & (1LL << j)))
                continue;

            if (!basis[j])
            {
                basis[j] = x;
                break;
            }

            x ^= basis[j];
        }
    }
    int ans = 0;
    for (int bit = 60; bit >= 0; bit--)
    {
        if ((ans ^ basis[bit]) > ans)
            ans ^= basis[bit];
    }

    cout << ans << "\n";

    return 0;
}