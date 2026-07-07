/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll PairsWithSumLessThan(vector<ll> &a, ll limit)
{

    ll cnt = 0;
    int left = 0, right = a.size() - 1;

    while (left < right)
    {
        if (a[left] + a[right] <= limit)
        {
            cnt += (right - left); // for this left right-left number of pairs
            left++;
        }
        else
        {
            right--; // reduce the element value
        }
    }

    return cnt;
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
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll Sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            Sum += a[i];
        }

        sort(a.begin(), a.end());

        ll L = Sum - y;
        ll R = Sum - x;

        ll ans = PairsWithSumLessThan(a, R) - PairsWithSumLessThan(a, L - 1);

        cout << ans << "\n";
    }

    return 0;
}