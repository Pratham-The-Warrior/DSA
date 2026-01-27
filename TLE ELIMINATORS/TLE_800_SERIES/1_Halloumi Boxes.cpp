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
        int n, k;
        cin >> n >> k;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        b = a;
        sort(b.begin(), b.end());

        if (a == b)
        {
            cout << "YES" << endl;
            continue;
        }

        if (k > 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
