/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ct = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 != 0)
            {
                ct++;
            }
        }

        if (ct % 2 == 0)
        {
            if (y % 2 == x % 2)
            {
                cout << "Alice\n";
            }
            else
                cout << "Bob\n";
        }
        else
        {
            if (y % 2 != x % 2)
            {
                cout << "Alice\n";
            }
            else
                cout << "Bob\n";
        }
    }

    return 0;
}