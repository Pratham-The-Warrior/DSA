// /* ************************************************
//  *                                                *
//  *       P     R     A     T     H     A     M      *
//  *                                                *
//  ************************************************ */

// #include <bits/stdc++.h>
// using namespace std;

// using ll = long long;

// bool check(ll k, const vector<ll> &a, ll n)
// {
//     ll need = 0, extra = 0;

//     unordered_map<ll, ll> mp;
//     for (ll x : a)
//         mp[x]++;

//     for (auto &x : mp)
//     {
//         ll ct = x.second;
//         if (k >= ct)
//             extra += (k - ct) / 2;
//         else
//             need += ct - k;
//     }

//     ll zero = n - mp.size();
//     extra += zero * (k / 2);

//     return need <= extra;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, m;
//         cin >> n >> m;

//         vector<ll> a(m);
//         for (ll i = 0; i < m; i++)
//         {
//             cin >> a[i];
//         }

//         ll l = 0, h = m, ans = -1;

//         while (l <= h)
//         {
//             ll mid = (l + h) / 2;

//             if (check(mid, a, n))
//             {
//                 ans = mid;
//                 h = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }

/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M      *
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
        int n, m; // m = tasks
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }

        map<int, int> mp;

        for (int i = 0; i < m; i++)
        {
            mp[a[i]]++; // i+1 task can be done in 1hr by workers in vector a[i]
        }

        // in second case for exam ple worker 1 is proficient in all tasks but it will be better if he do 3 works in 1hr and let worker2 do one work
        // this would make total time = max(3,2) => 3hr rather than 4

        // we will iterate over the map and get the max key value present
        //
        vector<int> hrs(n, 0);

        for (auto x : mp)
        {
            hrs[x.first - 1] = x.second; // number of tasks in which a worker is proficient
        }

        // now basically i have to reduce the maximum value of hrs i can reduce 1 from a particular and to compensate it i need to add +2
        // to any other elemnt

        // return the max_elemnt of hrs

        // binary search on the minimum time required
        int lo = 0, hi = 2 * m, ans = hi;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            ll total_tasks = 0;

            for (int i = 0; i < n; i++)
            {
                if (hrs[i] >= mid)
                {
                    total_tasks += mid; // proficient tasks done in 1hr each
                }
                else
                {
                    // remaining time can be used to do non-proficient tasks (2hr per task)
                    total_tasks += hrs[i] + (mid - hrs[i]) / 2;
                }
            }

            if (total_tasks >= m)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
