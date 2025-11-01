/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: House Robber
    ---------------------------------
    Given an array 'nums' where each element represents the amount of money in a house,
    find the maximum amount that can be robbed without robbing two adjacent houses.
*/

int rob(vector<int> &nums)
{
    int n = nums.size();

    // Base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // DP transition
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); // main logic
    }

    return dp[n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        cout << rob(nums) << "\n";
    }

    return 0;
}
