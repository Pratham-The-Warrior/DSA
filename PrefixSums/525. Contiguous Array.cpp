/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    int ct1 = count(nums.begin(), nums.end(), 0);
    int ct0 = count(nums.begin(), nums.end(), 1);
    if (ct0 == ct1)
        return n;

    unordered_map<int, int> mp;
    int curr = 0, ans = INT_MIN;
    mp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (nums[i - 1] == 1)
        {
            curr++;
        }
        else
        {
            curr--;
        }
        if (mp.count(curr))
        {
            int prev = mp[curr];
            ans = max(ans, i - prev);
        }
        else
        {
            mp[curr] = i;
        }
    }
    if (ans == INT_MIN)
        return 0;
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout << findMaxLength(nums) << endl;
    }

    return 0;
}