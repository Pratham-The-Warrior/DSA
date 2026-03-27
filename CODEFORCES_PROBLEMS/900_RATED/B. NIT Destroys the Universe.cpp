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

        int ct0 = count(a.begin(), a.end(), 0);

        if (ct0 == n)
        {
            cout << 0 << endl;
            continue;
        }
        if (ct0 == 0)
        {
            cout << 1 << endl;
            continue;
        }

        int ans = 0;
        bool inSegment = false;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != 0)
            {
                if (!inSegment)
                {
                    ans++;
                    inSegment = true;
                }
            }
            else
            {
                inSegment = false;
            }
        }

        cout << min(2, ans) << endl;
    }

    return 0;
}