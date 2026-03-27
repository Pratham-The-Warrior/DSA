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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

             int ct0 = count(a.begin(), a.end(), 0);

        if (ct0 == n)
        {
            cout << 0 << "\n";
            continue;
        }

        if (n % 2 == 0)
        {
            // Even case: 2 operations on the whole range
            cout << 2 << "\n";
            cout << 1 << " " << n << "\n";
            cout << 1 << " " << n << "\n";
        }
        else
        {
            // Odd case: 4 operations using overlapping even segments
            cout << 4 << "\n";
            // Make first n-1 elements zero
            cout << 1 << " " << n - 1 << "\n";
            cout << 1 << " " << n - 1 << "\n";
            // Make last 2 elements zero (indices n-1 and n)
            cout << n - 1 << " " << n << "\n";
            cout << n - 1 << " " << n << "\n";
        }
    }

    return 0;
}