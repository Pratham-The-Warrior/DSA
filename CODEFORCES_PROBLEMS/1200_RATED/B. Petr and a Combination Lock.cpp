/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
Petr has just bought a new car. He's just arrived at the most known Petersburg's petrol station to refuel it when he suddenly discovered that the petrol tank is secured with a combination lock! The lock has a scale of 360
degrees and a pointer which initially points at zero:
Petr called his car dealer, who instructed him to rotate the lock's wheel exactly n times. The i-th rotation should be ai
degrees, either clockwise or counterclockwise, and after all n
rotations the pointer should again point at zero.

his confused Petr a little bit as he isn't sure which rotations
should be done clockwise and which should be done counterclockwise. As there are many possible ways of rotating the lock, help him and find out whether the
there exists at least one, such that after all n
rotations the pointer will point at zero again.

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> angles(n);

    for (int i = 0; i < n; i++)
    {
        cin >> angles[i];
    }

    // i think we can do it exponentially as n is just upto 15
    // for every a[i] i have two choices clockwise or anticlockwise
    // if after all processing sum==0 || sum==360
    // we can say it is possible

    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                sum += angles[i]; // clockwise
            }
            else
            {
                sum -= angles[i];
            }
        }

        if (sum % 360 == 0)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}