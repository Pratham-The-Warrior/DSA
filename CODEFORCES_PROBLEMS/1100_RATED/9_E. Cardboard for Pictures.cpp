#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 lll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        ll c;
        cin >> n >> c;

        vector<ll> s(n);

        lll sum_s = 0;
        lll sum_sq = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            sum_s += (lll)s[i];
            sum_sq += (lll)s[i] * s[i];
        }

        lll A = 4 * (lll)n;
        lll B = 4 * sum_s;
        lll C = sum_sq - c;

        lll D = B * B - 4 * A * C;

        long double sqrtD = sqrt((long double)D);

        lll w = (-B + (lll)sqrtD) / (2 * A);

        cout << (long long)w << "\n";
    }

    return 0;
}