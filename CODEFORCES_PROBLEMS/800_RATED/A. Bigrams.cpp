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
        int k;
        cin >> k;
        vector<int> c(k);
        for (int i = 0; i < k; i++)
        {
            cin >> c[i];
        }
        bool ok = false;

        int cnt = 0;

        for (int i = 0; i < k; i++)
        {
            if (c[i] >= 2)
            {
                cnt++;
            }

            if (c[i] >= 3)
            {
                ok = true;
                break;
            }
        }

        if (ok || cnt >= 2)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }

    return 0;
}