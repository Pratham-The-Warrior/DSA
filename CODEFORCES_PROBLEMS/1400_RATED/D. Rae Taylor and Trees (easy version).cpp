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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> pref_min(n), suff_max(n);

        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < n - 1; i++)
        {
            mini = min(a[i], mini);
            pref_min[i] = mini;
        }

        for (int i = n - 1; i >= 1; i--)
        {
            maxi = max(maxi, a[i]);
            suff_max[i] = maxi;
        }

        bool ok = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (pref_min[i] > suff_max[i + 1])
            {
                ok = false;
            }
        }

        if (ok)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}