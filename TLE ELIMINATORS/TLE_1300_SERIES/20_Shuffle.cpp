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
        long long n, x, m;
        cin >> n >> x >> m;
        vector<pair<long long, long long>> p(m);

        for (int i = 0; i < m; i++)
        {
            long long a, b;
            cin >> a >> b;
            p[i] = {a, b};
        }

        long long L = x, R = x;
        bool found = false;

        for (int i = 0; i < m; i++)
        {
            long long a = p[i].first;
            long long b = p[i].second;

            if (b >= L && a <= R) 
            {
                found = true;
                L = min(L, a);
                R = max(R, b);
            }
        }

        if (!found)
            cout << 1 << endl;
        else
            cout << R - L + 1 << endl;
    }

    return 0;
}
