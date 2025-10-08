/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1; // base case: one way to have sum 0 before starting
    int preSum = 0;
    int ans = 0;

    for (int x : nums)
    {
        preSum += x;

        // Check if there was a prefix sum that, when removed, gives sum = k
        if (mp.count(preSum - k))
        {
            ans += mp[preSum - k]; // if between any two prefix sums we get k
        }

        // Record this prefix sum
        mp[preSum]++;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << subarraySum(nums, k) << endl;
    }

    return 0;
}