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
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long y_diff = d - b;

        if (y_diff < 0)
        {
            cout << -1 << endl;
            continue;
        }

        a = a + y_diff;

        if (a < c)
        {
            cout << -1 << endl;
            continue;
        }

        cout << y_diff + abs(c - a) << endl;
    }

    return 0;
}