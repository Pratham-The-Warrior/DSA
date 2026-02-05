#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        int c, d;
        cin >> c >> d;
        int e, f;
        cin >> e >> f;

        vector<pair<int, int>> dir = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};

        set<pair<int, int>> s1, s2;

        for (auto r : dir)
        {
            int p = c + r.first;
            int q = d + r.second;

            s1.insert(make_pair(p, q));

            int x = e + r.first;
            int y = f + r.second;

            s2.insert(make_pair(x, y));
        }
        int ans = 0;

        for (auto j : s1)
        {
            if (s2.find(j) != s2.end())
                ans++;
        }
        cout << ans << endl;
    }
}

int main()
{

    solve();
}