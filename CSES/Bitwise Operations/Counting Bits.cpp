/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/
/*
*PROBLEM STATEMENT
Task is to count the number of one bits in the
binary representations of integers between 1 and n.

n<=1e15
*/

/*
0 1 10 11 100 101 110 111 1000 1001 1010 1100 1101 1110 1111...
    1                       => 1
    1 2                     => 2
    1 2 2 3                 => 3
    1 2 2 2 3 3 4           => 4
    1 2 2 2 2 3 3 3 4 4     => 5

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

    ll ans = 0;

    for (int k = 1; k < 60; k++)
    {
        ll L = 1LL << (k - 1);
        ll R = (1LL << k) - 1;

        if (n >= R)
        {
            // full block
            ll total = (1LL << (k - 1)) + (k - 1) * (1LL << (k - 2));
            ans += total;
        }
        else
        {
            // partial block
            if (n < L)
                break;

            ll cnt = n - L + 1;

            // MSB contribution
            ans += cnt;

            // remaining bits
            for (int i = 0; i < k - 1; i++)
            {
                ll bit = 1LL << i;
                ll cycle = bit << 1;

                ll full_cycles = cnt / cycle;
                ll remainder = cnt % cycle;

                ans += full_cycles * bit;
                ans += max(0LL, remainder - bit);
            }

            break;
        }
    }

    cout << ans << endl;

    return 0;
}