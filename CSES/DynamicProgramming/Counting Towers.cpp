/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

//?Your task is to build a tower whose width is 2 and height is n.
//?You have an unlimited supply of blocks whose width and height are integers.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

/*
 *dp[i][j] = ways to build height i such that the top layer is in configuration j (connected or split)
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    const int MAXN = 1e6 + 1;
    // dp[i][0]=>connected
    // dp[i][1]=>split
    vector<vector<ll>> dp(MAXN, vector<ll>(2));
    dp[1][0] = 1; // height 1 connected top block
    dp[1][1] = 1; // height 1 splited top block

    for (int i = 2; i < MAXN; i++)
    {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD; // 2* becoz 2 possiblities => one combine big block other seprate block//and for dp[i-1][1] =>one way only that is one block on top
        dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % MOD; // here *4 becoz 4 ways possible all 4 block split , 2 split one join , one join two split,2 combine block
    }
    while (t--)
    {
        int n;
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/
//*Variations

/*
*1️. Wider Towers (Width > 2)
*Goal: Build a tower of height = n and width = w using 1×1 or 1×2 blocks (dominoes).
*You can place blocks horizontally or vertically.
*Count the number of valid towers.
    for mask in 0..(2^w - 1):
        for each valid filling of open columns in mask:
            next_mask = resulting mask after filling
            dp[next_row][next_mask] += dp[current_row][mask]



*2.Colored Towers
*Constraint: No two adjacent blocks (horizontally or vertically) can have the same color.
*Count the number of valid colored towers.




*/
