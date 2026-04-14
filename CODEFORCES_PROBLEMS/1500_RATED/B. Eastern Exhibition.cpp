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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
     *Problem-Statement
     *You and your friends live in n
     *houses. Each house is located on a 2D plane, in a point with integer coordinates.
     *There might be different houses located in the same point.
     * The mayor of the city is asking you for places for the building of the Eastern exhibition.
     *You have to find the number of places (points with integer coordinates),
     *so that the summary distance from all the houses to the exhibition is minimal.
     *The exhibition can be built in the same point as some house.
     *The distance between two points (x1,y1) and (x2,y2) is |x1−x2|+|y1−y2|, where |x| is the absolute value of x.
     */

    /*
    =====================  MEDIAN CONCEPT NOTES =====================

    Whenever you see:
        SUM |x - a[i]|  → think MEDIAN

    Because:
        Median minimizes sum of absolute differences.

    ------------------------------------------------------------

    WHY THIS PROBLEM USES MEDIAN?

    Distance = |x - xi| + |y - yi|

    This splits into:
        SUM |x - xi|   +   SUM |y - yi|

    So we solve independently:
        - Find best x
        - Find best y

    ------------------------------------------------------------

    n is ODD:
        - Only ONE median exists
        - Only ONE optimal point
        → answer = 1

    n is EVEN:
        - Median is NOT unique
        - Any value in range:
              [x[n/2 - 1], x[n/2]]
          gives SAME minimum cost

        Count of such integers:
              x[n/2] - x[n/2 - 1] + 1

        Same for y

        Final answer:
              (x choices) * (y choices)

    ------------------------------------------------------------
     IMPORTANT VARIATIONS WHERE MEDIAN IS USED:

    1️ Minimize sum of absolute differences:
        → Use MEDIAN

    2️ 2D Manhattan distance:
        → Take median of x and median of y separately

    3️ Make all array elements equal (min operations):
        → Convert all to median

    4️ Meeting point / gathering problem:
        → Median position

    5️ Post office problem (1D):
        → Place at median

    ------------------------------------------------------------

     INTUITION (VERY IMPORTANT):

    For EVEN n:
        The cost function becomes FLAT between two medians.

        That means:
            Moving inside this range DOES NOT change cost

        → Hence multiple valid answers

    ------------------------------------------------------------
  */

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        vector<ll> x(n), y(n);

        for (int i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            x[i] = a;
            y[i] = b;
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        // ll median1 = (n % 2 == 1 ? (x[(n + 1) / 2] + x[(n - 1) / 2]) / 2 : x[n / 2]); //odd case

        if (n & 1)
        {
            cout << 1 << endl;
        }

        else
        {
            ll median_x = x[(n + 1) / 2] - x[(n - 1) / 2] + 1;
            ll median_y = y[(n + 1) / 2] - y[(n - 1) / 2] + 1;

            cout << 1LL * median_x * median_y << endl;
        }
    }

    return 0;
}