/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long double get_dist(long double x1, long double y1, long double x2, long double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;

        long double oa = get_dist(0, 0, ax, ay);
        long double ob = get_dist(0, 0, bx, by);
        long double pa = get_dist(px, py, ax, ay);
        long double pb = get_dist(px, py, bx, by);
        long double ab = get_dist(ax, ay, bx, by);

        // case 1: Lantern A covers both the origin and the house
        long double w1 = max(oa, pa);

        // case 2: Lantern B covers both the origin and the house
        long double w2 = max(ob, pb);

        // case 3: Lantern A covers origin, Lantern B covers house, and they meet/overlap
        long double w3 = max({oa, pb, ab / 2.0});

        // case 4: Lantern B covers origin, Lantern A covers house, and they meet/overlap
        long double w4 = max({ob, pa, ab / 2.0});

        long double ans = min({w1, w2, w3, w4});

        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}