/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

    int maxi = 0;

    for (int i = 1; i <= text1.size(); i++)
    {
        for (int j = 1; j <= text2.size(); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                maxi = max(dp[i][j], maxi);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                // dp[i][j] = dp[i-1][j];
            }
        }
    }
    return maxi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string t1, t2;
        cin >> t1 >> t2;

        cout << longestCommonSubsequence(t1, t2) << endl;
    }

    return 0;
}