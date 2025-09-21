/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    set<vector<int>> temp;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int l = i + 1;
        int h = n - 1;

        while (l < h)
        {
            int sum = nums[i] + nums[l] + nums[h];

            if (sum < 0)
            {
                l++;
            }
            else if (sum > 0)
            {
                h--;
            }
            else
            {
                temp.insert({nums[i], nums[l], nums[h]});
                l++;
                h--;
            }
        }
    }
    for (auto x : temp)
    {
        ans.push_back(x);
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<vector<int>> ans = threeSum(nums);

        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}