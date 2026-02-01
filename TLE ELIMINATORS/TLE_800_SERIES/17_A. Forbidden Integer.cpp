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
        int n, k, x;
        cin >> n >> k >> x;

        if (x != 1)
        {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }

        if (x == 1 && k == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        if (x == 1 && k == 2)
        {
            if (n == 5 || n == 3)
            {
                cout << "NO" << endl;
                continue;
            }
        }

        if (x == 1)
        {
            if (n % 2 != 0)
            {
                int n2 = (n - 3) / 2;
                cout << "YES" << endl;
                cout << n2 + 1 << endl;
                for (int i = 1; i <= n2; i++)
                    cout << 2 << " ";
                cout << 3 << " ";
                cout << endl;
                continue;
            }
            else
            {
                int n2 = n / 2;
                cout << "YES" << endl;
                cout << n2 << endl;
                for (int i = 1; i <= n2; i++)
                    cout << 2 << " ";
                cout << endl;
            }
        }
    }

    return 0;
}