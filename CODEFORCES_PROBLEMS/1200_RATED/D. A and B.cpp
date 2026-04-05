#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min_swaps(vector<ll> &v)
{
    if (v.empty())
        return 0;
    // 2 5 6 8
    // 2 4 4 5
    int median = v.size() / 2;
    ll res = 0;

    for (int i = 0; i < v.size(); i++)
    {
        res += abs(v[median] - v[i]);
        res -= abs(median - i);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<ll> a, b;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                a.push_back(i);
            }
            else
            {
                b.push_back(i);
            }
        }

        ll ans1 = min_swaps(a);
        ll ans2 = min_swaps(b);

        cout << min(ans1, ans2) << endl;
    }

    return 0;
}