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

        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        long long ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= i)
                continue;
            for (int j = i + 1; j <= n; j++)
            {
                if (i < a[j] && a[j] < j)
                {
                    ans++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
