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
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                a[i] += 1;
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i + 1] % a[i] == 0)
            {
                a[i + 1] += 1;
            }
        }

        for (auto x : a)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}