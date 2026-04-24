/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll count_upto(ll val, ll rem)
{
    if (val < rem)
        return 0LL;
    return (val - rem) / 4 + 1; //+1 becoz zeroth position gets missed
    //*rem, rem+4, rem+8, rem+12...
}

ll count(ll l, ll r, ll k)
{
    // this function will calculate how many terms between l and r have
    // modulo by 4 == k

    if (l > r)
    {
        return 0;
    }

    return count_upto(r, k) - count_upto(l - 1, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        ll n, x;
        cin >> n >> x;

        ll left0 = 1; // 0 always
        ll left1 = 0;

        left0 += count(1, x - 1, 3);
        left1 = count(1, x - 1, 1);

        ll right0 = count(x, n, 3);
        ll right1 = count(x, n, 1);
        ll ans = ((left0 % MOD) * (right0 % MOD) % MOD + (left1 % MOD) * (right1 % MOD) % MOD) % MOD;
        //*Every left index with value 0 can pair with every right index with value 0.
        cout << ans << endl;
    }

    return 0;
}