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
        vector<vector<int>> arr(n);

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            arr[i].resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        }

    return 0;
}