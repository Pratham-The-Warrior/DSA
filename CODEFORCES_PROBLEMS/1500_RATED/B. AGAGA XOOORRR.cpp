#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
fundamental property of the XOR operation: the total XOR sum of an array never changes when you merge adjacent elements.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // prefix XORs
        vector<ll> px(n);
        px[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            px[i] = px[i - 1] ^ a[i];
        }

        ll total = px[n - 1];

        if (total == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        bool ok = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {

                ll x1 = px[i];

                ll x2 = px[j] ^ px[i];

                ll x3 = px[n - 1] ^ px[j];

                if (x1 == x2 && x2 == x3)
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
                break;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}