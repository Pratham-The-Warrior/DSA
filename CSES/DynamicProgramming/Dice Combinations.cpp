/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

// Recursive solution O(6^n)

ll solveRec(ll x)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;

    ll ways = 0;
    for (int i = 1; i <= 6; i++)
    {
        ways = ways + solveRec(x - i);
    }

    return ways;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    /* ===============================================
       Problem:
       Count the number of ways to construct sum n
       using dice throws (values from 1 to 6)

       Base Case:
       dp[0] = 1

       Let dp[x] = number of ways to get sum x

       Recurrence:
       dp[x] = dp[x-1] + dp[x-2] + dp[x-3]
             + dp[x-4] + dp[x-5] + dp[x-6]

       (only if x - i >= 0)

       Time Complexity: O(6 * n)
       =============================================== */

    ll n;
    cin >> n;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (ll x = 1; x <= n; x++)
    {
        for (ll i = 1; i <= 6; i++)
        {
            if (x - i >= 0)
            {
                dp[x] = (dp[x] + dp[x - i]) % mod;
            }
        }
    }

    cout << dp[n] << endl;
    // cout << solveRec(n);

    return 0;
}

/****************************************VARIATIONS**************************************/

/*
*Variation 1: Exact K Throws
 Count the number of ways to get sum n using exactly k dice throws.

 Here 2D DP will be needed

 dp[x][y] = number of ways to make sum x using y moves

 base case => dp[0][0]=0;

 Recurrence Relation => dp[x][y] = dp[x-i][y-1] i=[1,6],x-i>=0

 Code:

 ll n,k;cin>>n>>k;

 vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));

 dp[0][0]=1;

    for(ll x=1;x<=n;x++){
        for(ll throws=1;throws<=k;throws++){
            for(ll dice =1;dice<=6;dice++){
                dp[x][throws] += dp[x-dice][throws-1];
            }
        }
    }

    return dp[n][k];

---------------------------------------------------------------------------------------

*Variation 2: Order Doesn’t Matter

Count the number of ways to construct sum n
using dice throws 1–6, but order does not matter.
Examples: 1+2 and 2+1 are the same
Base case: dp[0] = 1

This is like the Coin Change (combinations) problem.

Code:

    ll n;
    cin >> n;

    vector<ll> dp(n+1, 0);
    dp[0] = 1; // base case

    for (int dice = 1; dice <= 6; dice++) {
        for (int sum = dice; sum <= n; sum++) {
            dp[sum] = (dp[sum] + dp[sum - dice]) % mod;
        }
    }

For each dice value, we only build sums using this dice and previous smaller dice
This prevents counting the same combination in a different order

----------------------------------------------------------------------------------------

*Variation 3: Minimum Dice Throws to Reach Sum n

You have a dice (1–6)
You want to reach sum n using the fewest number of throws
Each throw adds 1–6 to your sum
Base case: sum 0 → 0 throws

    dp[x] = min no of throws to reach sum x

    recurrence => dp[x] = min(dp[x-i]+1) x-i>=0 , i=[1,6]

    int n;
    cin>>n;
    vector<int>dp(n+1,INT_MAX)
    for(int x=1;x<=n;x++){
        for(int dice=1;dice<=6;dice++){
            if(x-dice>=0 && dp[x-dice]!=INT_MAX){
                dp[x] = min(dp[x-i]+1,dp[i]);
            }
        }
    }

    return dp[n];

------------------------------------------------------------------------------------------

*Variation 4: Limited Frequency Dice Problem
*/