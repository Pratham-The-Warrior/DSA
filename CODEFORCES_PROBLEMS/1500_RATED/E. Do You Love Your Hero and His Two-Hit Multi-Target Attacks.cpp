/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// helper functions
ll distance(ll xa, ll xb, ll ya, ll yb)
{
}

ll manhattan(ll xa, ll xb, ll ya, ll yb)
{
}

/*
n<=500

to get regular distnce ==  manhattan ditnace guess the situation will be
only when both the points are either on same line
or parallel to each other

k pairs

the number of points i will place on same line will
give me n*(n-1)/2 pairs count
so try to get excatly or nearest value to k
if val<k
satisfy by placinf that many points parallel to the exiisting
elements in the line

this way we can get exactly k pairs
also as k<=1e5 so
we will always need less than 500 points only

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int k;
        cin >> k;

        if (k == 0)
        {
            cout << 1 << endl;
            cout << 0 << " " << 0 << endl;
            continue;
        }

        vector<pair<ll, ll>> points;
        int y = 0, x = 0;

        while (k > 0)
        {
            int m = 2; // least value for nC2

            while ((m + 1) * (m - 1 + 1) / 2 <= k) // as we are checking next pair
            {
                m++;
            }

            for (int i = 0; i < m; i++)
            {
                points.push_back({x, y}); // m points in this row giving m*(m-1)/2 pairs
                x++;
            }

            k -= (m * (m - 1) / 2);
            y++;
        }

        cout << points.size() << endl;
        for (auto p : points)
        {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}