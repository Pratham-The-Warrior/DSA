#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n + 2, 0);

        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        ll ct = 0;

        for (ll i = 2; i <= n; i += 2)
        {
            ll need = max(0LL, a[i - 1] + a[i + 1] - a[i]);

            if (need > 0)
            {
                ll reduce_left = max(0LL, a[i - 1] - a[i]);
                reduce_left = min(reduce_left, need);

                a[i - 1] -= reduce_left;
                ct += reduce_left;
                need -= reduce_left;

                ll reduce_right = min(need, a[i + 1]);
                a[i + 1] -= reduce_right;
                ct += reduce_right;
            }
        }

        cout << ct << endl;
    }

    return 0;
}