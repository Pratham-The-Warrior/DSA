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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int mini = 1e9;
        bool zero = false;
        int cnt = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 0)
                {
                    zero = true;
                }
                if (a[i][j] < 0)
                {
                    cnt++;
                }
                mini = min(mini, abs(a[i][j]));
                sum += abs(a[i][j]);
            }
        }

        // f t f t

        if (zero)
        {
            cout << sum << endl;
        }
        else if (cnt % 2 == 0)
        {
            cout << sum << endl;
        }
        else
        {
            cout << sum - 2 * mini << endl;
        }
    }

    return 0;
}