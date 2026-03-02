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
        string s;
        cin >> s;

        int n = s.size();

        int ct0 = count(s.begin(), s.end(), '0');

        if (ct0 == 0)
        {
            cout << 1LL * n * n << endl;
            continue;
        }

        string doubled = s + s;

        int l = 0, curr = 0;
        for (char c : doubled)
        {
            if (c == '1')
            {
                curr++;
                l = max(l, curr);
            }
            else
            {
                curr = 0;
            }
        }

        l = min(l, n);

        ll ans = 0;

        // exactly your loop logic
        ll j = 1;
        for (ll i = l; i >= 1; i--)
        {
            ans = max(ans, i * j);
            j++;
        }

        cout << ans << endl;
    }
    return 0;
}