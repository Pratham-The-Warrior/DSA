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
    n actions need to be performed
    one case is count all non szero elements we can than  choose the largest l and r i.r l=0,r=ct-1
    other case is
    when 1 1 1 1 1
    to do n ops size of each interval need to be sum - (n-1) =?

    2 1 1 1 1
    1 1 1 0 1

    also the minimum sum>=n or we wont be able to perform n oprations

    3 5 4 2 1

    ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        ll sum = 0;
        ll ct = 0;

        for (int i = 0; i < n; ++i)
        {
            int val;
            cin >> val;
            if (val > 0)
            {
                ct++;
            }
            sum += val;
        }

        ll ans = min(ct, sum - (n - 1));

        cout << ans << endl;
    }

    return 0;
}