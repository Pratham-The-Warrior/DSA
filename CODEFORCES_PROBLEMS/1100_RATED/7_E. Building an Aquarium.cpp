/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(long long h, vector<long long> &a, long long x)
{
    long long val = 0;

    for (int i = 0; i < a.size(); i++)
    {
        val += max(0LL, h - a[i]);
    }

    return val <= x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    i feel binary search on h may work
    for the h make a check function if it is possible or not if possible
    ans = mid , low = mid+1
    else high = mid-1
    */

    int t;
    cin >> t;
    while (t--)
    {

        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long low = 1, high = 1e10;

        long long ans = 0;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (check(mid, a, x))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}