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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // edge case for all zero
        bool chk = true;

        for (auto x : a)
        {
            if (x != 0)
            {
                chk = false;
                break;
            }
        }

        if (chk)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
            continue;
        }

        int g = 0;

        for (int bit = 0; bit < 30; bit++)
        {
            int ct = 0;
            for (auto x : a)
            {
                if (x & (1 << bit))
                {
                    ct++;
                }
            }

            if (ct > 0)
            {
                g = (g == 0) ? ct : __gcd(g, ct);
            }
        }

        vector<int> ans;
        for (int k = 1; k <= n; k++)
        {
            if (g % k == 0)
            {
                ans.push_back(k);
            }
        }

        sort(ans.begin(), ans.end());
        for (int k : ans)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}