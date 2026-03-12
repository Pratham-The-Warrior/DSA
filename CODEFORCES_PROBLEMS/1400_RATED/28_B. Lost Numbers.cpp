#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long x;
        cin >> n >> x;

        long long base = 0; // distance without any rollbacks
        long long best = 0; // best extra distance per rollback

        for (int i = 0; i < n; i++)
        {
            long long a, b, c;
            cin >> a >> b >> c;

            base += a * (b - 1);

            long long delta = a * b - c;
            best = max(best, delta);
        }

        if (base >= x)
        {
            cout << 0 << '\n';
        }
        else if (best <= 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            long long need = x - base;
            long long ans = (need + best - 1) / best; // ceil division
            cout << ans << '\n';
        }
    }

    return 0;
}
