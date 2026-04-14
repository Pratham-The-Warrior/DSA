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

    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    //* dp[i][j] = the minimum number of operations to transform the prefix A[1..i] into the prefix B[1...j].
    /*
    If string A is empty (i=0), we must insert all j characters of B:dp[0][j] = j If string B is
     empty (j=0), we must delete all i characters of A:dp[i][0] = i
    */
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }

    cout << dp[n][m];

    return 0;
}