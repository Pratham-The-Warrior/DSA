/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != i)
            {
                ans &= (i & a[i]);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
