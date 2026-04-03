/**************************************************
 * *
 * P  R  A  T  H  A  M                     *
 * *
 **************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/**
 * LOGIC: Square Root Decomposition Insight
 * ----------------------------------------
 * Problem: Find pairs (i, j) such that a[i] * a[j] = j - i.
 * Constraint: 0 <= i < j < n.
 * * Observation:
 * Since j - i < n, then a[i] * a[j] must be < n.
 * If the product of two positive integers is < n, at least one
 * of them must be <= sqrt(n).
 * * Complexity: O(T * N * sqrt(N))
 */

void solve()
{
    int n;
    if (!(cin >> n))
        return;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    int B = sqrt(n);

    // Case 1: a[i] is the "small" value (a[i] <= B)
    // We check all indices j and derive what index i must be.
    for (int v = 1; v <= B; v++)
    {
        for (int j = 0; j < n; j++)
        {
            // From a[i] * a[j] = j - i, if a[i] = v:
            // i = j - v * a[j]
            ll i = (ll)j - (ll)v * a[j];

            if (i >= 0 && i < j && a[i] == v)
            {
                ans++;
            }
        }
    }

    // Case 2: a[j] is the "small" value (a[j] <= B)
    // We only consider a[i] > B here to prevent double-counting pairs
    // where both values are <= B (already handled in Case 1).
    for (int v = 1; v <= B; v++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > B)
            {
                // From a[i] * a[j] = j - i, if a[j] = v:
                // j = i + a[i] * v
                ll j = (ll)i + (ll)a[i] * v;

                if (j < n && a[j] == v)
                {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}