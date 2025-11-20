/* ************************************************
 *                                                *
 *   ALL VERSIONS OF SUBSET SUM IN ONE FILE       *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

// =====================================================
// 1. Brute Force (Bitmask)
// =====================================================
bool subsetSum_bruteforce(const vector<int> &a, int target)
{
    int n = a.size();
    for (int mask = 0; mask < (1 << n); mask++)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                sum += a[i];
        }
        if (sum == target)
            return true;
    }
    return false;
}

// =====================================================
// 2. Backtracking
// =====================================================
bool subsetSum_backtrack(int idx, long long currentSum, const vector<int> &a, int target)
{
    if (currentSum == target)
        return true;
    if (idx == a.size())
        return false;

    // include element
    if (subsetSum_backtrack(idx + 1, currentSum + a[idx], a, target))
        return true;

    // exclude element
    if (subsetSum_backtrack(idx + 1, currentSum, a, target))
        return true;

    return false;
}

// =====================================================
// 3. Dynamic Programming (DP Table) – O(n * target)
// =====================================================
bool subsetSum_dp(const vector<int> &a, int target)
{
    if (target < 0)
        return false;
    int n = a.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            dp[i][t] = dp[i - 1][t];
            if (t - a[i - 1] >= 0)
                dp[i][t] = dp[i][t] || dp[i - 1][t - a[i - 1]];
        }
    }
    return dp[n][target];
}

// =====================================================
// 4. DP Using Bitset – O(n * target / 64)
// Very fast for target ≤ 2e6
// =====================================================
bool subsetSum_bitset(const vector<int> &a, int target)
{
    bitset<100001> dp; // increase if needed
    dp[0] = 1;

    for (int x : a)
        dp |= (dp << x);

    return dp[target];
}

// =====================================================
// 5. Meet-in-the-Middle (MITM)
// Best for n > 30
// =====================================================
void genSubsetSums(int idx, int end, long long sum, const vector<int> &a, vector<long long> &result)
{
    if (idx == end)
    {
        result.push_back(sum);
        return;
    }
    genSubsetSums(idx + 1, end, sum, a, result);
    genSubsetSums(idx + 1, end, sum + a[idx], a, result);
}

bool subsetSum_mitm(const vector<int> &a, int target)
{
    int n = a.size();
    int mid = n / 2;

    vector<long long> left, right;
    genSubsetSums(0, mid, 0, a, left);
    genSubsetSums(mid, n, 0, a, right);

    sort(right.begin(), right.end());

    for (long long x : left)
    {
        long long need = target - x;
        if (binary_search(right.begin(), right.end(), need))
            return true;
    }
    return false;
}

// =====================================================
// MAIN DRIVER
// =====================================================
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n--- RESULTS ---\n";

    cout << "Brute Force:           "
         << (subsetSum_bruteforce(a, target) ? "YES" : "NO") << "\n";

    cout << "Backtracking:          "
         << (subsetSum_backtrack(0, 0, a, target) ? "YES" : "NO") << "\n";

    // Only works for non-negative target
    if (target >= 0)
        cout << "DP Table:              "
             << (subsetSum_dp(a, target) ? "YES" : "NO") << "\n";

    // Bitset version (requires small target)
    if (target <= 100000 && target >= 0)
        cout << "Bitset DP:             "
             << (subsetSum_bitset(a, target) ? "YES" : "NO") << "\n";

    cout << "Meet-in-the-Middle:    "
         << (subsetSum_mitm(a, target) ? "YES" : "NO") << "\n";

    return 0;
}
