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
        int n;
        cin >> n;

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        vector<int> ans(n);

        bool ok = true;

        for (int i = 0; i < n;)
        {
            int j = i;

            // find group of equal values
            while (j < n && a[j].first == a[i].first)
                j++;

            int len = j - i;

            if (len == 1)
            {
                ok = false;
                break;
            }

            // rotate indices in this group
            for (int k = i; k < j; k++)
            {
                int next = (k + 1 == j ? i : k + 1);
                ans[a[k].second] = a[next].second;
            }

            i = j;
        }

        if (!ok)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
                cout << ans[i] + 1 << " ";
            cout << "\n";
        }
    }

    return 0;
}