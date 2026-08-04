/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(ll k)
{

    // like
    // suppose we want to find numbers till
    // 10000
    // it will be 12345..910...11
    // 9+90+900+9000+
    // 9 + 90*2 + 900*3 + 9000*4 + ...

    // 9+180+2700+1777*4+
    //  1777 1778
    //=>for 10000 answer will be 7
    // so we can reach the point

    // case 19
    //  19-9
    //  10
    // 10/2 => 5
    // 5th two digit number will be answer

    ll j = 1;
    ll digits = 1;

    while (k > 9LL * j * digits)
    {
        k -= 9LL * j * digits;
        j *= 10;
        digits++;
    }

    ll ans = j + (k - 1) / digits;
    string s = to_string(ans);

    return s[(k - 1) % digits] - '0';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--)
    {
        ll k;
        cin >> k;

        cout << solve(k) << "\n";
    }

    return 0;
}