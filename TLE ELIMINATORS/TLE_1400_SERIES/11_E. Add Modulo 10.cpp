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

        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;

        bool hasA = false, hasB = false;

        for (auto x : a)
        {
            if (x % 10 == 0 || x % 10 == 5)
                hasA = true;
            else
                hasB = true;
        }

        if (hasA && hasB)
        {
            cout << "No\n";
            continue;
        }

        // Group A
        if (hasA)
        {
            for (auto &x : a)
            {
                if (x % 10 == 5)
                    x += 5;
            }

            bool ok = true;
            for (int i = 1; i < n; i++)
            {
                if (a[i] != a[0])
                {
                    ok = false;
                    break;
                }
            }

            cout << (ok ? "Yes\n" : "No\n");
        }
        // Group B
        else
        {
            for (auto &x : a)
            {
                while (x % 10 != 2)
                {
                    x += x % 10;
                }
            }

            bool ok = true;
            for (int i = 1; i < n; i++)
            {
                if (a[i] % 20 != a[0] % 20)
                {
                    ok = false;
                    break;
                }
            }

            cout << (ok ? "Yes\n" : "No\n");
        }
    }

    return 0;
}
