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

        for (int i = n; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << n << " ";
        for (int i = 1; i <= n - 1; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        // 3 2 1 3 1 2
    }

    return 0;
}