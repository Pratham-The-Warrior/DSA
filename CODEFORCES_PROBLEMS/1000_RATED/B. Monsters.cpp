/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

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
        // Your code here
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<pair<ll, ll>> v(n);

        // for (int i = 0; i < n; i++)
        // {
        //     ll rem = a[i] % k;
        //     v[i] = {rem, i + 1};
        // }

        for (int i = 0; i < n; i++)
        {
            ll rem = a[i] % k;
            if (rem == 0)
                rem = k;
            v[i] = {rem, i + 1};
        }

        sort(v.begin(), v.end(), [](pair<ll, ll> &a, pair<ll, ll> &b)
             {
                 if (a.first == b.first)
                     return a.second < b.second; // Smaller index first
                 return a.first > b.first;       // LARGER remainder first (Descending)
             });

        vector<ll> ans(n);

        for (int i = 0; i < n; i++)
        {
            ans[i] = v[i].second;
        }

        for (auto x : ans)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}