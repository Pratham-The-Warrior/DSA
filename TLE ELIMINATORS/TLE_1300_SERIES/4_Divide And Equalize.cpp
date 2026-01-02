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

        unordered_map<int, long long> cnt;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            for (int p = 2; p * p <= x; p++)
            {
                while (x % p == 0)
                {
                    cnt[p]++;
                    x /= p;
                }
            }
            if (x > 1)
                cnt[x]++;
        }

        bool ok = true;
        for (auto &pair : cnt)
        {
            if (pair.second % n != 0)
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
