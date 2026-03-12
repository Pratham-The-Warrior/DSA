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

        /*

        */

        int maxi = a[0];
        int curr = a[0];
        int ans = INT_MIN;

        for (int i = 1; i < n; i++)
        {

            if (abs(a[i]) % 2 == abs(a[i - 1]) % 2)
            {
                curr = 0;
            }

            if (curr < 0)
            {
                curr = 0;
            }

            curr += a[i];

            maxi = max(maxi, curr);
        }

        cout << maxi << endl;
    }

    return 0;
}