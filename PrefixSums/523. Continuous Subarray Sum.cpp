/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int preSum = 0;
    // the core logic of the problem is suppose
    // We compute the running sum of the array and take (sum % k)
    // at each step. The remainder represents the residue of the
    // total sum modulo k up to the current index.
    //
    // If the same remainder has appeared before, it means that the
    // difference between the two prefix sums (the sum up to the
    // current index and the sum up to the previous index where the
    // same remainder was seen) is divisible by k.
    //
    // Therefore, the subarray between those two indices has a sum
    // that is a multiple of k. We also ensure that the length of
    // this subarray is at least 2 before returning true.

    mp[0] = -1; // first pe hi aggayaya cant take

    for (int i = 0; i < n; i++)
    {
        preSum += nums[i];

        // if (k != 0)
        preSum %= k;

        if (mp.count(preSum))
        {
            if (i - mp[preSum] >= 2)
            {
                return true;
            }
        }
        else
        {
            mp[preSum] = i;
        }
    }
    return false;
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
        cout << checkSubarraySum(nums, k) << endl;
    }

    return 0;
}