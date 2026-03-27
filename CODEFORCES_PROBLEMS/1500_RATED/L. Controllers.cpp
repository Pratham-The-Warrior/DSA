/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    Initaill score is 0
    i have two numbers a and b and some operations
    i want to find is there a way to do n operation on score and still end up with 0

    */

    int n;
    cin >> n;
    string s;
    cin >> s;

    int plus_ct = count(s.begin(), s.end(), '+');
    int minus_ct = count(s.begin(), s.end(), '-');

    int q;
    cin >> q;
    if (plus_ct == minus_ct)
    { // we can always make zero
        for (int i = 0; i < q; i++)
        {
            cout << "YES" << endl;
        }
        return 0;
    }
    for (int i = 1; i <= q; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "NO" << endl;
            continue;
        }
        ll lc = lcm(a, b);
        ll x = lc / a, y = lc / b;
        if (abs(plus_ct - minus_ct) % abs(y - x) == 0)
        {
            ll p = abs(plus_ct - minus_ct) / abs(y - x);
            if ((x + y) * p > n)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}