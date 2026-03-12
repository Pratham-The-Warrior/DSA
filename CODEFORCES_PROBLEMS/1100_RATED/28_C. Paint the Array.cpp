#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll find_valid_d(const vector<ll> &a, int start)
{
    ll d = 0;
    int n = a.size();

    // Compute GCD of all elements alternte //
    for (int i = start; i < n; i += 2)
    {
        d = __gcd(d, a[i]);
    }

    for (int i = 1 - start; i < n; i += 2)
    {
        if (a[i] % d == 0)
            return 0;
    }

    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);

        for (ll &x : a)
            cin >> x;

        ll d1 = find_valid_d(a, 0); // even indices red
        ll d2 = find_valid_d(a, 1); // odd indices red
        if (d2)
        {
            cout << d2 << "\n";
        }
        else if (d1)
        {
            cout << d1 << endl;
        }
        else
        {
            cout << "0" << "\n";
        }
    }

    return 0;
}