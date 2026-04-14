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

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    int n, x;
    cin >> n >> x;
    int mn = INT_MIN, mx = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        mn = max(mn, a);
        mx = min(mx, b);
    }

    if (mx - mn < 0)
    {
        cout << -1 << endl; // no intersection
    }
    else if (mx < x)
    {
        cout << x - mx << endl;
    }
    else if (mn > x)
    {
        cout << mn - x << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}