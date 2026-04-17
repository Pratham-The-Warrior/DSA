#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Given two arrays of integers, find their longest common subsequence.
    A subsequence is a sequence of array elements from left to right that can contain gaps.
    A common subsequence is a subsequence that appears in both arrays.

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;

    int i = n, j = m;

    vector<int> lcs;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        { // “From where did this dp value come?”
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    for (auto x : lcs)
    {
        cout << x << " ";
    }

    return 0;
}

//*------------------------------------------------------------------------------------------------------------------------*//

/*
*Varition 1

*Instead of printing just one LCS, we must print:
*All possible longest common subsequences between two arrays.

solve(i, j) => Meaning : “Return ALL LCS sequences between a[0..i-1] and b[0..j-1]”

base case :

    if (i == 0 || j == 0)
        return { {} }; onloy LCS is empty sequence



*/

/*
*VARIATION 2: COUNT NUMBER OF DISTINCT LCS

1. dp[i][j] → LCS length (same as before)
2. cnt[i][j] → number of distinct LCS of that length



*/

/*
*  ****VARIATION 3: Lexicographically Smallest LCS
*The LCS with maximum length, and among all such LCS,

return the lexicographically smallest one.

define a function :-
solve(i, j) → returns lexicographically smallest LCS from (i, j)



*/
/*
vector<vector<int>> dp;

vector<int> solve(int i, int j, vector<int> &a, vector<int> &b)
{
    if (i == 0 || j == 0)
    {
        return {};
    }

    if (a[i - 1] == b[j - 1])
    {
        vector<int> res = solve(i - 1, j - 1, a, b);
        res.push_back(a[i - 1]);
        return res;
    }

    if (dp[i - 1][j] > dp[i][j - 1])
    {
        return solve(i - 1, j, a, b);
    }

    if (dp[i - 1][j] < dp[i][j - 1])
    {
        return solve(i, j - 1, a, b);
    }

    // tie
    vector<int> up = solve(i - 1, j, a, b);
    vector<int> left = solve(i, j - 1, a, b);

    return min(up, left); // lexicographically smaller vector
}

*/