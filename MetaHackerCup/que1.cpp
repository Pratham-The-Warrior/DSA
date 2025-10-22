/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int minL = 0;

        for (int i = 1; i < n; ++i)
        {
            minL = max(minL, abs(a[i] - a[i - 1]));
        }

        cout << "Case #" << tc << ": " << minL << endl;
    }
}
