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
        long long n, m;
        cin >> n >> m;
        vector<long long> k(n), c(m);
        for (int i = 0; i < n; i++)
            cin >> k[i];
        for (int i = 0; i < m; i++)
            cin >> c[i];

        sort(k.rbegin(), k.rend());
        long long ans = 0;
        long long j = 0;

        for (int i = 0; i < n; i++)
        {
            long long idx = k[i] - 1;
            if (j < m && j < idx)
            {
                ans += c[j++];
            }
            else
            {
                ans += c[idx];
            }
        }
        cout << ans << endl;
    }
}
