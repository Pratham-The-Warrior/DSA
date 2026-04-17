/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

//*Recursive version
ll binpow(ll a, ll b)
{

    if (b == 0)
    {
        return 1;
    }

    ll half = binpow(a, b / 2) % MOD;

    if (b % 2 == 0)
    {
        return (half * half) % MOD;
    }
    else
    {
        return (a * half % MOD * half) % MOD;
    }
}

//*iterative
ll binpowIterative(ll a, ll b)
{

    ll res = 1;

    while (b > 0)
    {
        if (b % 2 == 1)
        { // odd case
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        cout << binpowIterative(a, b) << endl;
    }

    return 0;
}