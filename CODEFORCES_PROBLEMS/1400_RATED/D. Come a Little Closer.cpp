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
        cin >> n;
        vector<pair<long long, long long>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;

        if (n <= 2)
        {
            cout << n << "\n";
            continue;
        }

        // Store top 2 min/max for X and Y
        vector<long long> xs(n), ys(n);
        for (int i = 0; i < n; i++)
        {
            xs[i] = v[i].first;
            ys[i] = v[i].second;
        }

        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());

        long long minX1 = xs[0], minX2 = xs[1];
        long long maxX1 = xs[n - 1], maxX2 = xs[n - 2];
        long long minY1 = ys[0], minY2 = ys[1];
        long long maxY1 = ys[n - 1], maxY2 = ys[n - 2];

        long long ans = LLONG_MAX;
        bool tightExists = false;

        for (int i = 0; i < n; i++)
        {
            long long x = v[i].first, y = v[i].second;

            long long newMinX = (x == minX1) ? minX2 : minX1;
            long long newMaxX = (x == maxX1) ? maxX2 : maxX1;
            long long newMinY = (y == minY1) ? minY2 : minY1;
            long long newMaxY = (y == maxY1) ? maxY2 : maxY1;

            long long width = newMaxX - newMinX + 1;
            long long height = newMaxY - newMinY + 1;
            long long area = width * height;

            // Check if tight rectangle (no vacant spot)
            if (area == n - 1)
            {
                ans = min({ans, (width + 1) * height, (height + 1) * width});
            }
            else
            {
                ans = min(ans, area);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
