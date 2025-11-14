/* https://codeforces.com/gym/648798/problem/C  */
// TRY THIS

/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
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
    }

    return 0;
}

int n, d;
vector<int> v;
int go(int mid)
{
    int i = 0;

    int count = 0;
    while (i < n)
    {
        int sum = 0;
        count++;
        while (i < n && sum + v[i] <= mid)
        {
            sum += v[i] + 1;
            i++;
        }
        // debug(i);
        // debug(count);
    }

    return count;
}

void solve()
{
    cin >> n >> d;
    v.clear();
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = -1;

    int lo = *max_element(v.begin(), v.end());
    int hi = 1e18;
    // debug(go(6));
    // return;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (go(mid) == d)
        {
            l = mid;
            hi = mid - 1;
        }
        else if (go(mid) < d)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    int r = -1;

    lo = *max_element(v.begin(), v.end());
    hi = 1e18;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (go(mid) == d)
        {
            r = mid;
            lo = mid + 1;
        }
        else if (go(mid) < d)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    cout << l << " " << r << endl;
}
