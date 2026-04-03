#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    multiset<ll> h;
    vector<ll> t(m);

    // Read ticket prices
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        h.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
    }

    for (int i = 0; i < m; i++)
    {
        auto it = h.upper_bound(t[i]);

        if (it == h.begin())
        {
            cout << -1 << '\n';
        }
        else
        {
            it--;
            ll val = *it;
            h.erase(it);
            cout << val << '\n';
        }
    }

    return 0;
}