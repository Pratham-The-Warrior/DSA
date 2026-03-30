/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(2 * n + 1);
    vector<int> existing_values;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
        { // Values > n can never satisfy a[i]*a[j] < n
            if (pos[a[i]].empty())
                existing_values.push_back(a[i]);
            pos[a[i]].push_back(i);
        }
    }

    ll ans = 0;
    // Sort existing values to allow breaking the inner loop early
    sort(existing_values.begin(), existing_values.end());

    for (int v1 : existing_values)
    {
        for (int v2 : existing_values)
        {
            ll dist = (ll)v1 * v2;
            if (dist >= n)
                break; // v2 is too large, and so will be subsequent ones

            // We need to count pairs (i, j) where a[i]=v1, a[j]=v2, and j-i=dist
            // Optimization: Iterate over the shorter position list
            if (pos[v1].size() < pos[v2].size())
            {
                for (int i : pos[v1])
                {
                    int j = i + (int)dist;
                    if (j < n && a[j] == v2)
                        ans++;
                }
            }
            else
            {
                for (int j : pos[v2])
                {
                    int i = j - (int)dist;
                    if (i >= 0 && a[i] == v1)
                        ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ====================================

    a[i].a[j] == j-i

    (j-i) = {1,2,..n-1}

    a[i]={1,2,4}

 c


    a[i]  = {1,2}


    obs:-
        j-i will always be less than n so any value of a[i]>=n is useless we can ignore those indices
        i am getting a feeling that real optimization can be hidden in     (j-i) = {1,2,..n-1}


     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {

        // BRUTE
        // ll n;
        // cin >> n;
        // vector<ll> a(n);
        // for (int i = 0; i < n; i++)
        // {
        //     cin >> a[i];
        // }

        // ll ans = 0;

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         if (a[i] * a[j] == j - i)
        //         {
        //             ans++;
        //         }
        //     }
        // }

        // //we have to optimize this
        // //nlogn is acceptable
        // cout << ans << endl;

        // OPTIMIZED

        // ll ans = 0;
        // for (int i = 0; i < n; i++)

        // {

        //     if (a[i] > n)
        //         continue;
        //     // j - i must be a multiple of a[i]
        //     // So j = i + a[i], i + 2*a[i], i + 3*a[i], ...
        //     for (ll j = (ll)i + a[i]; j < n; j += a[i])
        //     {
        //         if (a[i] * a[j] == (ll)j - i)
        //         {
        //             ans++;
        //         }
        //     }
        // }

        // cout << ans << endl;

        // OPTIMIZED
        solve();
    }

    return 0;
}