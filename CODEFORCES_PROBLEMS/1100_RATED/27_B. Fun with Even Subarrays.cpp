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
        ll n;
        cin >> n;
        vector<ll> a(n);
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ct = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == a[0])
            {
                ct++;
            }
        }

        if (ct == n)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = 0, end = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == a[n - 1])
            {
                end++;
            }
            else
            {
                i -= end;
                ans++;
                end += end;
                i++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}