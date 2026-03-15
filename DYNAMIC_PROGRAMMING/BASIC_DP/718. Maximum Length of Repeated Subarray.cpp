/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));

    int maxi = 0;

    for (int i = 1; i <= nums1.size(); i++)
    {
        for (int j = 1; j <= nums2.size(); j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                maxi = max(dp[i][j], maxi);
            }
        }
    }
    return maxi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        vector<int> nums1(n1), nums2(n2);

        for (int i = 0; i < n1; i++)
        {
            cin >> nums1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> nums2[i];
        }

        cout << findLength(nums1, nums2) << endl;
    }

    return 0;
}