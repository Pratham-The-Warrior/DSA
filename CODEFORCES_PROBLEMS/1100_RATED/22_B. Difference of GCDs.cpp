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
        ll n, l, r;
        cin >> n >> l >> r;

        vector<ll> ans;
        bool ok = true;

        for (int i = 1; i <= n; i++)
        {
            ll val = ((l + i - 1) / i) * i;
            if (val > r)
            {
                ok = false;
                break;
            }
            ans.push_back(val);
        }
        if (ok)
        {

            cout << "YES" << endl;

            for (auto x : ans)
                cout << x << " ";
        }
        else
        {
            cout << "NO" << endl;
        }
        cout << endl;
    }

    return 0;
}