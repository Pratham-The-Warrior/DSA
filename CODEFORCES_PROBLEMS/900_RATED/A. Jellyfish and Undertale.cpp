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
        ll a, b, n;
        cin >> a >> b >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        ll ans = b;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {

            ans += min(1LL * x[i], a - 1);
            if (ans <= 0)
                break;
        }

        cout << ans << endl;
    }

    return 0;
}