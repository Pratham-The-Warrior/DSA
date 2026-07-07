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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*
        Kind of like Knapsack.

        At each turn, a player has two choices:
        1. Take the first element.
        2. Take the last element.

        Since both players play optimally, we define:

            DP[i][j]

        as the maximum score difference (current player - opponent)
        obtainable from the subarray a[i...j].

        Transition:

        Take the first element a[i]:
            - Remaining subarray: a[i + 1 ... j]
            - Opponent can achieve DP[i + 1][j]
            - Net gain:
                  a[i] - DP[i + 1][j]

        Take the last element a[j]:
            - Remaining subarray: a[i ... j - 1]
            - Opponent can achieve DP[i][j - 1]
            - Net gain:
                  a[j] - DP[i][j - 1]

        Therefore:

            DP[i][j] = max(
                            a[i] - DP[i + 1][j],
                            a[j] - DP[i][j - 1]
                           )

        Base Case:

            DP[i][i] = a[i]

        because only one element remains.
    */

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)

        return 0;
}