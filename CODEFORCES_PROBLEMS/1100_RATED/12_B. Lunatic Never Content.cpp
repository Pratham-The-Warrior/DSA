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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ok = false;

        long long g = 0;

        for (int i = 0; i < n / 2; i++)
        {
            g = __gcd(abs(a[i] - a[n - i - 1]), g);
        }

        cout << g << endl;
    }

    return 0;
}