#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;

    int pw = 1;
    long long ans = 0;

    // Build pw as (2^k - 1) >= r
    while (pw < r)
    {
        pw = (pw << 1) | 1;
    }

    unordered_set<int> s;
    for (int i = l; i <= r; i++)
    {
        s.insert(i);
    }

    vector<int> a(r + 1, 0);

    for (int i = r; i >= l; i--)
    {
        while (s.find(pw - i) == s.end())
        {
            pw >>= 1;
        }
        a[i] = pw - i;
        ans += (i | a[i]);
        s.erase(pw - i);
    }

    cout << ans << endl;
    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}