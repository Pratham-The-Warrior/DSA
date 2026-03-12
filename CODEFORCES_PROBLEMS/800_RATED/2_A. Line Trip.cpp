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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = (x - a[n - 1]) * 2;

        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, a[i + 1] - a[i]);
        }

        cout << max(ans, a[0]) << endl;
    }

    return 0;
}