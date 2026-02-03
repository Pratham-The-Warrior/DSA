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

        if (n % k != 0)
        {
            cout << 1 << endl;
            cout << n << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << n - k - 1 << " " << k + 1 << endl;
        }
    }

    return 0;
}