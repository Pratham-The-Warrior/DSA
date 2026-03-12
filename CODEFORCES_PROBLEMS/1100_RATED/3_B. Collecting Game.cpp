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

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {a[i], i};
    }

    sort(v.begin(), v.end());
    sort(a.begin(), a.end());

    // prefix sums
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    ll mx = 0;
    int lastReach = 0;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int x = i;

        if (pref[x] > mx)
        {
            while (x < n - 1 && pref[x] >= a[x + 1])
            {
                x++;
                mx = pref[x];
            }
            lastReach = x;
        }

        ans[v[i].second] = lastReach;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
