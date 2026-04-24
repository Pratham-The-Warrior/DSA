/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
Your task is to calculate the number of trailing zeros in the factorial n!.
For example, 20!=2432902008176640000 and it has 4 trailing zeros.
*/

/*
zeros=n/5​+n/25​+n/125​+n/625​+...
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n; // n<=1e12

    // trailing zeroes means 2 and 5 multiples
    // find how many
    // i have to do it  root n i guess

    ll ans = 0;
    while (n > 0)
    {
        n /= 5;
        ans += n;
    }

    cout << ans;

    return 0;
}