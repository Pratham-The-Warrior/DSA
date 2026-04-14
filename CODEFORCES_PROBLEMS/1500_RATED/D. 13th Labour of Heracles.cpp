/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

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

        vector<ll> a(n);
        ll curr = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            curr += a[i];
        }

        vector<int> degree(n, 0);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            degree[u]++;
            degree[v]++;
        }

        vector<ll> gains;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < degree[i] - 1; j++)
            {
                gains.push_back(a[i]);
            }
        }

        sort(gains.rbegin(), gains.rend());

        cout << curr << " "; // k==1
        for (auto g : gains)
        {
            curr += g; // k==2 .. 3
            cout << curr << " ";
        }
        cout << endl;
    }

    return 0;
}