/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
        for every element i will have to precompute  last occuring index
        as 1<=a[i]<=1000 so there will be lot of repetitive values
        then start iterating over each value of in set of a[i]
        ans = 0
        for x in set:
            for y in set:
                if coprime:
                ans = max(ans,lastidx of x + lastidx of y)
    */
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }

        // last occurrence index of each number
        map<ll, ll> lastIdx;
        for (int i = 0; i < n; i++)
        {
            lastIdx[a[i]] = i + 1;
        }

        ll ans = 0;
        for (auto x : s)
        {
            for (auto y : s)
            {
                if (__gcd(x, y) == 1)
                {
                    ans = max(ans, lastIdx[x] + lastIdx[y]);
                }
            }
        }

        cout << (ans == 0 ? -1 : ans) << endl;
    }

    return 0;
}