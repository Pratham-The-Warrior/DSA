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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int i = 0, j = n - 1;
        long long sum1 = 0, sum2 = 0;
        int ans = 0;

        // try avoidng any assumption without full proof

        while (i <= j)
        {
            if (sum1 <= sum2)
            {
                sum1 += a[i++];
            }
            else
            {
                sum2 += a[j--];
            }

            if (sum1 == sum2)
            {
                ans = max(ans, i + (n - 1 - j));
            }
        }

        cout << ans << endl;
    }

    return 0;
}