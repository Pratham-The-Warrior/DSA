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

    choose two interger x and y
    *x and y must be 1<=y<x<=k*
    and ensure that x/y exist in vector q
    and x%y exists in vector r
    if found remove those occurences from vector q and r

    * The problem reduces to matching r[j] <= (k - q[i]) / (q[i] + 1).
    * We calculate these limits for each q[i], sort them, and sort r.
    * Then use two pointers to find the maximum matching.

    *T(n) ~ O(nlogn)

     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> q(n), r(n);
        multiset<ll> r_set;
        for (int i = 0; i < n; i++)
        {
            cin >> q[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
            r_set.insert(r[i]);
        }

        vector<long long> limits;
        for (int i = 0; i < n; ++i)
        {
            if (q[i] < k)
            {
                limits.push_back((k - q[i]) / (q[i] + 1));
            }
        }

        int ct = 0;
        sort(limits.begin(), limits.end());
        for (ll lim : limits)
        {
            if (r_set.empty())
                break;

            auto it = r_set.upper_bound(lim);

            if (it == r_set.begin())
                continue; // no element found <=limit

            it--;

            ct++;

            r_set.erase(it);
        }
        cout << ct << endl;
    }

    return 0;
}