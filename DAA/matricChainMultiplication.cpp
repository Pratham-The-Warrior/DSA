#include <bits/stdc++.h>
using namespace std;

// Matrix Chain Multiplication using Dynamic Programming
int matrixChainOrder(int p[], int n)
{
    // dp[i][j] = minimum cost to multiply matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // L is chain length
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            // Find minimum cost by trying all possible splits
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1];
}

int main()
{
    // Example: A1 (10×20), A2 (20×30), A3 (30×40), A4 (40×30)
    // Dimensions array is: {10, 20, 30, 40, 30}
    int p[] = {10, 20, 30, 40, 30};
    int n = sizeof(p) / sizeof(p[0]);

    cout << "Minimum number of multiplications: "
         << matrixChainOrder(p, n) << endl;

    return 0;
}
