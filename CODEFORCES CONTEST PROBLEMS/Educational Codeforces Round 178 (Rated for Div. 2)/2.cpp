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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> pmax(n);
        pmax[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            pmax[i] = max(pmax[i - 1], a[i]);
        }

        // Suffix sum array
        vector<ll> suff(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            suff[i] = a[i] + suff[i + 1];
        }

        vector<ll> ans(n);
        for (int k = 1; k <= n; k++)
        {
            ll max_first = (n - k >= 0) ? pmax[n - k] : 0;
            ll sum_last = suff[n - k + 1];
            ans[k - 1] = max_first + sum_last;
        }

        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
