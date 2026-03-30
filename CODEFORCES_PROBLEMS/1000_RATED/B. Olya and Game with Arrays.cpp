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

     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> m1, m2;

        for (int i = 1; i <= n; i++)
        {
            int m;
            cin >> m;
            vector<ll> a(m);
            ll min1 = 1e10, min2 = 1e10;
            for (int i = 0; i < m; i++)
            {

                cin >> a[i];
                if (a[i] < min1)
                {
                    min2 = min1;
                    min1 = a[i];
                }
                else if (a[i] < min2)
                {
                    min2 = a[i];
                }
            }
            m1.push_back(min1);
            m2.push_back(min2);
        }

        ll ans = *min_element(m1.begin(), m1.end());

        sort(m2.begin(), m2.end());

        for (int i = 1; i < n; i++)
        {
            ans += m2[i];
        }

        cout << ans << endl;

        /*
        7 5
        6 8
        2 9
        9 8 7
        2 5 6 7 8 9

        */
    }

    return 0;
}