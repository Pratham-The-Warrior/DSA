#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        /*
        keep 2 multisets
        one for odd position elemnsts other for even position elements

        iterate over array b

        check if the position is odd or even
        if it is odd and a[pos]>0
        then from the odd multiset find the max value >0 we can remove
        and remove it
        if not found i.e no positive value

        we will choose the largest value multiple times
        */

        multiset<long long> odd, even;

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                even.insert(a[i]);
            else
                odd.insert(a[i]);
        }

        bool need1 = false, need2 = false;
        bool has1 = false, has2 = false;
        long long trackedodd = 0, trackedeven = 0;

        for (int i = 0; i < m; i++)
        {
            if (b[i] & 1)
            { // odd query
                need1 = true;
                if (!odd.empty() && *prev(odd.end()) > 0)
                {
                    auto it = prev(odd.end());
                    trackedodd += *it;
                    odd.erase(it);
                    has1 = true;
                }
            }
            else
            { // even query
                need2 = true;
                if (!even.empty() && *prev(even.end()) > 0)
                {
                    auto it = prev(even.end());
                    trackedeven += *it;
                    even.erase(it);
                    has2 = true;
                }
            }
        }

        if (need1 && !has1 && !odd.empty())
            trackedodd += *prev(odd.end());
        if (need2 && !has2 && !even.empty())
            trackedeven += *prev(even.end());

        cout << total - trackedodd - trackedeven << endl;
    }
}