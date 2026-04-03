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

    /* ====================================
THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL

use two pointer
if a large number gets us increment in (s+a[r]/x) value
take it this will give better bonus += a[r]
else choose small element
continue this greedy algo
     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        ll n, X;
        cin >> n >> X;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        ll S = 0, bonus = 0;
        int l = 0, r = n - 1;
        vector<int> ans;

        while (l <= r)
        {
            if ((S + a[r]) / X > S / X)
            {
                S += a[r];
                bonus += a[r];
                ans.push_back(a[r]);
                r--;
            }
            else
            {
                // take cheapest item
                S += a[l];
                ans.push_back(a[l]);
                l++;
            }
        }

        cout << bonus << endl;
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}