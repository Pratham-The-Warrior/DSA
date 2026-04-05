#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* ************************************************
 * *
 * P    R    A    T    H    A    M       *
 * *
 ************************************************ */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials up to 14! (15! exceeds 10^12, 20! fits in ll)
    // Note: 1! and 2! are already powers of 2, so we can start from 3!
    // to avoid redundancy, but bitmasking all of them works too.
    vector<ll> factorials;
    ll f = 1;
    for (int i = 1; i <= 15; i++)
    {
        f *= i;
        if (f > 1e12)
            break;
        if (f > 2)
            factorials.push_back(f);
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        int m = factorials.size();
        int min_elements = __builtin_popcountll(n);

        for (int i = 0; i < (1 << m); i++)
        {
            ll current_sum = 0;
            int count_fact = 0;

            for (int j = 0; j < m; j++)
            {
                if ((i >> j) & 1)
                {
                    current_sum += factorials[j];
                    count_fact++;
                }
            }

            if (current_sum <= n)
            {
                // The remaining value must be represented by powers of 2
                // __builtin_popcountll(remaining) gives the minimum powers of 2 needed
                ll remaining = n - current_sum;
                int current_total = count_fact + __builtin_popcountll(remaining);
                min_elements = min(min_elements, current_total);
            }
        }

        cout << min_elements << endl;
    }

    return 0;
}