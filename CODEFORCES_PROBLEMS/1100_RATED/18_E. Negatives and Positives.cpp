/* ************************************************
 * *
 * P     R     A     T     H     A     M    *
 * *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    operation can be performed anytimes
    in a operation -> take any adjacent elemnsts flip their signs
    this will be benificial if overall sum of that
    */

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum1 = 0, ct = 0;
        ll mini = 2e18;
        bool zero = false;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
            {
                ct++;
            }
            if (a[i] == 0)
                zero = true;

            sum1 += llabs(a[i]);
            mini = min(mini, llabs(a[i])); // Minimum absolute value regardless of sign
        }

        if (ct % 2 == 0 || zero)
        {
            // If negatives are even or a zero exists, we can make everything positive
            cout << sum1 << endl;
        }
        else
        {
            // If odd, we must leave the smallest absolute value as a negative
            cout << sum1 - 2 * mini << endl;
        }
    }

    return 0;
}