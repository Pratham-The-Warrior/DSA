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

    /* ====================================

     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        if (n & 1 || n < 4)
        {
            cout << -1 << endl;
            continue;
        }

        long long maxi = n / 4;
        long long mini = (n + 5) / 6;

        cout << mini << " " << maxi << endl;
    }

    return 0;
}