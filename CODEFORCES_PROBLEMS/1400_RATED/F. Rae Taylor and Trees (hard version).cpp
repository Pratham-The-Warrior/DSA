#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> pre_min(n + 1, 2e9);
    vector<pair<int, int>> suf_max(n + 2, {0, 0});

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pre_min[i] = min(pre_min[i - 1], p[i]);
    }

    // Store {value, index} to easily find where the suffix max is located
    for (int i = n; i >= 1; i--)
    {
        if (p[i] > suf_max[i + 1].first)
        {
            suf_max[i] = {p[i], i};
        }
        else
        {
            suf_max[i] = suf_max[i + 1];
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (pre_min[i - 1] > suf_max[i].first)
        {
            cout << "No" << "\n";
            return;
        }
    }

    cout << "Yes" << "\n";
    for (int l = 1; l <= n;)
    {
        int r = suf_max[l].second;
        int leader = p[r];

        // Connect everything in the current block to the block leader
        for (int i = l; i < r; i++)
        {
            cout << p[i] << " " << leader << "\n";
        }

        // Connect this block leader to the global minimum seen so far
        if (l > 1)
        {
            cout << pre_min[l - 1] << " " << leader << "\n";
        }

        l = r + 1; // Move to the start of the next block
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}