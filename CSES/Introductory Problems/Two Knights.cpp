/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*CSES Problem Set-Two Knights

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    for (ll k = 1; k <= n; k++)
    {
        ll total = (k * k) * (k * k - 1) / 2;
        ll attack = 4 * (k - 1) * (k - 2);
        cout << total - attack << "\n";
    }

    return 0;
}