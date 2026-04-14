#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        bool ok = true;
        for (auto &p : freq)
        {
            if (p.second % k != 0)
            {
                ok = false;
            }
        }

        if (!ok)
        {
            cout << 0 << endl;
            continue;
        }

        map<int, int> mp;
        int r = -1;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (r < n - 1)
            {
                if (mp[a[r + 1]] < freq[a[r + 1]] / k)
                {
                    mp[a[r + 1]]++;
                    r++;
                }
                else
                {
                    break;
                }
            }
            ans += (r - i + 1);
            mp[a[i]]--;
        }

        cout << ans << endl;
    }
}