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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        if (k == 2)
        {
            bool ok = false;
            for (int x : a)
            {
                if (x % 2 == 0)
                {
                    ok = true;
                    break;
                }
            }
            cout << (ok ? 0 : 1) << '\n';
        }

        else if (k == 3)
        {
            int ans = INT_MAX;
            for (int x : a)
            {
                if (x % 3 == 0)
                {
                    ans = 0;
                    break;
                }
                else if (x % 3 == 2)
                {
                    ans = min(ans, 1);
                }
                else
                {
                    ans = min(ans, 2);
                }
            }
            cout << ans << '\n';
        }

        else if (k == 4)
        {
            int cnt2 = 0;
            for (int x : a)
            {
                if (x % 4 == 0)
                    cnt2 += 2;
                else if (x % 2 == 0)
                    cnt2 += 1;
            }

            if (cnt2 >= 2)
            {
                cout << 0 << '\n';
            }
            else
            {
                int best = INT_MAX;

                // Option 1: make one number divisible by 4
                for (int x : a)
                {
                    int need = (4 - x % 4) % 4;
                    best = min(best, need);
                }

                // Option 2: make two numbers even
                int odd = 0;
                for (int x : a)
                {
                    if (x % 2)
                        odd++;
                }
                best = min(best, odd);

                cout << best << '\n';
            }
        }

        else if (k == 5)
        {
            int ans = INT_MAX;
            for (int x : a)
            {
                ans = min(ans, (5 - x % 5) % 5);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}