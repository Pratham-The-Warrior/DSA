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
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int ans = 1, maxi = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] - a[i] <= k)
            {
                ans++;
            }
            else
            {
                maxi = max(ans, maxi);
                ans = 1;
            }
        }

        maxi = max(ans, maxi);

        cout << n - maxi << endl;
    }

    return 0;
}