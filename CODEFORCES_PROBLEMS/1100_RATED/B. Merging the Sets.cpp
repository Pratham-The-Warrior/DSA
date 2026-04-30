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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n);
        vector<int> freq(m + 1, 0);

        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            v[i].resize(l);

            for (int j = 0; j < l; j++)
            {
                cin >> v[i][j];
                if (v[i][j] <= m)
                    freq[v[i][j]]++;
            }
        }

        bool ok = true;
        for (int i = 1; i <= m; i++)
        {
            if (freq[i] == 0)
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << "NO" << endl;
            continue;
        }

        int good_groups = 0;

        for (int i = 0; i < n; i++)
        {
            bool valid = true;

            for (int x : v[i])
            {
                if (x <= m && freq[x] == 1)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                good_groups++;

            if (good_groups >= 2)
                break;
        }

        cout << (good_groups >= 2 ? "YES" : "NO") << endl;
    }

    return 0;
}