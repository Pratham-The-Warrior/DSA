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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        b = a;
        sort(b.begin(), b.end());

        if (a == b)
        {
            cout << "yes" << endl;
            continue;
        }

        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (a[i] > a[i - 1] && a[i] > a[i + 1])
                {
                    swap(a[i], a[i + 1]);
                }
            }
        }
        if (a == b)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }

        cout << "\n";
    }

    return 0;
}