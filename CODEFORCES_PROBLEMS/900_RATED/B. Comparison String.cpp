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
        string s;
        cin >> s;

        int ct = 1, c2 = 1, ans = 0;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                ct++;
            }
            else
            {
                ans = max(ct, ans);
                ct = 1;
            }
        }
        ans = max(ans, ct);
        cout << ans + 1 << endl;
    }

    return 0;
}