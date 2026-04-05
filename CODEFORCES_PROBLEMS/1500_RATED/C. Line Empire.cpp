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

    /* ====================================
     we need O(n) approach
     so we will have to

     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<ll> suffix_sum(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            suffix_sum[i] = suffix_sum[i + 1] + arr[i];
        }

        // first case :- Capital stays at 0, conquer everyone from there
        ll cost = b * suffix_sum[0];

        for (int i = 0; i < n; i++)
        {
            // Cost = (Move capital to arr[i]) + (Conquer kingdoms after i from arr[i])
            ll move_capital = (a + b) * arr[i];
            ll remaining_kingdoms_count = (n - 1 - i);
            ll conquer_rem = b * (suffix_sum[i + 1] - (remaining_kingdoms_count * arr[i]));

            ll curr_cost = move_capital + conquer_rem;

            if (curr_cost < cost)
            {
                cost = curr_cost;
            }
        }

        cout << cost << endl;
    }

    return 0;
}