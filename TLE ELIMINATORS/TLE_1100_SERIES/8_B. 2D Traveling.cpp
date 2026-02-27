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

    /*
    i may do it this way -> choose the point of such major city which is nearest to end
    and one major city that is nearest to start
    in this case answer will be abs(end-nearest1) + abs(start-nearest2)
    */

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<ll, ll>> p(n);

        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        pair<ll, ll> start = p[a - 1];
        pair<ll, ll> end = p[b - 1];

        vector<pair<ll, ll>> major;

        for (int i = 0; i < k; i++)
        {
            major.push_back({p[i].first, p[i].second});
        }

        ll mn1 = 1e10;
        ll mn2 = 1e10;
        ll base = llabs(start.first - end.first) + llabs(start.second - end.second);
        for (auto x : major)
        {
            ll val1 = llabs(1LL * x.first - 1LL * start.first) + llabs(1LL * x.second - 1LL * start.second);
            ll val2 = llabs(1LL * x.first - 1LL * end.first) + llabs(1LL * x.second - 1LL * end.second);
            mn1 = min(mn1, val1);
            mn2 = min(mn2, val2);
        }

        cout << min(base, mn1 + mn2) << endl;
    }

    return 0;
}