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

    /*
    3 5 => 3 3 + 3 2
    3 5 => 3 3 + 2 2 + 1 1
    ans = 3

    */

    /*
    *dp[i][j] = minimum number of cuts needed to convert an i × j rectangle into squares

    dp[i][i]=0 already a square
    */

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0; // no cuts required already a square
            }
            else
            {

                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
                }

                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
                }
            }
        }
    }

    cout << dp[a][b];

    return 0;
}

/******************************************************************************************/

//*variation 1 Minimize number of squares used (instead of cuts)

/*
dp[i][j] = minimum number of squares needed to form i × j
dp[i][i] = 1   A square itself counts as 1 piece

code:
         int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            // Base case: already a square
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else
            {
                // Vertical cuts
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j],
                                   dp[k][j] + dp[i - k][j]);
                }

                // Horizontal cuts
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }

    cout << dp[a][b] << '\n';

*/

/***********************************************************************************/
//*Variation 3: Count Number of Ways
/*
 You can cut it into two rectangles
 Repeat until all pieces are squares
*Count how many different ways exist to do this.
*dp[i][j] = number of ways to completely cut i × j into squares


#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    vector<vector<long long>> dp(a + 1, vector<long long>(b + 1, 0));

    // Base case
    for (int i = 1; i <= a; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j) continue;

            // Vertical cuts
            //*i × j → (k × j) + ((i-k) × j)
            for (int k = 1; k < i; k++)
            {
                dp[i][j] += dp[k][j] * dp[i - k][j];
            }

            // Horizontal cuts
            for (int k = 1; k < j; k++)
            {
                dp[i][j] += dp[i][k] * dp[i][j - k];
            }
        }
    }

    cout << dp[a][b] << '\n';

    return 0;
}
*/