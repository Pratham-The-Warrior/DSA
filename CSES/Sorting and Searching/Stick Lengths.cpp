/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
There are n sticks with some lengths.
Your task is to modify the sticks so that each stick has the same length.
You can either lengthen and shorten each stick.
Both operations cost x where x is the difference between the new and original length.
What is the minimum total cost?

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    ll median = 0;

    if (n & 1)
    {
        median = p[n / 2];
    }
    else
    {
        median = (p[(n + 1) / 2] + p[(n - 1) / 2]) / 2;
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += llabs(p[i] - median);
    }

    cout << ans;

    /*

    */

    return 0;
}