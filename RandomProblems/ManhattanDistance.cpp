/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

/*
Piggy lives on an infinite plane with a Cartesian coordinate system.

There are n cities on the plane, numbered from 1 to n.
The first k cities are defined as *major cities*.
The coordinates of the i-th city are (xi, yi).

Piggy is currently in city a and wants to travel to city b by air.
He can take any number of flights between cities, but his final destination must be b.

The flight cost f(i, j) between cities i and j is defined as:
    f(i, j) = 0,                  if both i and j are major cities
    f(i, j) = |xi - xj| + |yi - yj|, otherwise

Your task:
Find the minimum possible total cost Piggy must pay to reach city b from city a.
*/

#include <bits/stdc++.h>
using namespace std;

/* ---------------- Utility Function ---------------- */

// Manhattan distance between two points
inline long long manhattanDist(long long x1, long long y1, long long x2, long long y2)
{
    return llabs(x1 - x2) + llabs(y1 - y2);
}

/* ------------------- Main Function ------------------- */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        long long n, k, a, b;
        cin >> n >> k >> a >> b;

        vector<pair<long long, long long>> cities(n);
        for (int i = 0; i < n; ++i)
            cin >> cities[i].first >> cities[i].second;

        pair<long long, long long> start = cities[a - 1];
        pair<long long, long long> endp = cities[b - 1];

        // Direct Manhattan distance
        long long directDist = manhattanDist(start.first, start.second, endp.first, endp.second);

        // Case 1: both are major cities => free flight
        if (a <= k && b <= k)
        {
            cout << 0 << '\n';
            continue;
        }

        // Case 2: at least one is not major
        long long minToMajorFromStart = LLONG_MAX;
        long long minToMajorFromEnd = LLONG_MAX;

        for (int i = 0; i < k; ++i)
        {
            long long x = cities[i].first;
            long long y = cities[i].second;

            minToMajorFromStart = min(minToMajorFromStart, manhattanDist(start.first, start.second, x, y));
            minToMajorFromEnd = min(minToMajorFromEnd, manhattanDist(endp.first, endp.second, x, y));
        }

        // Compute minimal route cost
        long long viaMajor = LLONG_MAX;
        if (minToMajorFromStart != LLONG_MAX && minToMajorFromEnd != LLONG_MAX)
            viaMajor = minToMajorFromStart + minToMajorFromEnd;

        cout << min(directDist, viaMajor) << '\n';
    }

    return 0;
}
