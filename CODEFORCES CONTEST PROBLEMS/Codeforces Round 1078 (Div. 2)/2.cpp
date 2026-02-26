#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long long n, x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long ans = 0, prev = 0, idx = 0, maxi = 0;

        for (int i = 0; i < n; i++)
        {
            ans += (a[i] / x) * y;

            maxi = max(maxi, a[i] - (a[i] / x) * y);
        }

        cout << ans + maxi << endl;
    }
}
