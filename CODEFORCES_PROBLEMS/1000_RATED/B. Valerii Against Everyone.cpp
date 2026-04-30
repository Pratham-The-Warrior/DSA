/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        vector<ll> b(n);
        map<ll, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mp[b[i]]++;
        }

        // for each b[i] check if we can find
        // a subarry that equals to it

        // or run a sliding window from each to check wherether that b[i] can be found or not
        // 16 = 8 + 4 + 2 + 1

        bool ok = false;

        for (auto x : mp)
        {
            if (x.second >= 2)
            {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}