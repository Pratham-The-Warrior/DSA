/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
#define ll long long
const ll mod = 1e9 + 7;
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    ll ans = n % mod;
    ans = ans * ((n + 1) % mod) % mod;
    ans = ans * ((4 * n - 1) % mod) % mod;
    ans = ans * 337 % mod; // 2022/6 = 337

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
/*
1 2
2 4

1 2 3
2 4 6
3 6 9

1 2 4 6 9


1 2 3 4
2 4 6 8
3 6 9 12
4 8 12 16

1 2 4 6 9 12 16


sum n^2 + (n+1)*(n+2)*n/3

2 6 12 20...
1 3 6 10...
*/