/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int d = 0;

        for (int k = 0; k < n; k++)
        {

            while (d <= k && a[k - d] >= d + 1) // imp logic
            {
                d++;
            }
            cout << d << " ";
        }

        cout << endl;
    }

    return 0;
}