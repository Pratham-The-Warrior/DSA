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

        int ct2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 2)
                ct2++;
        }

        if (ct2 % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }
        int ct = 0, ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == 2)
            {
                ct++;
            }
            if (ct == ct2 / 2)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}