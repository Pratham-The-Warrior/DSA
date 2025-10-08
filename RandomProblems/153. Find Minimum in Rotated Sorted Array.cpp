/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{

    int low = 0, high = nums.size() - 1;
    int smallest = INT_MAX;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid])
        {
            // sorted
            smallest = min(smallest, nums[low]);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
            smallest = min(smallest, nums[mid]);
        }
    }
    return smallest;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> nums;
        for (int i = 0; i < nums.size(); i++)
        {
            cin >> nums[i];
        }
        cout << findMin(nums) << endl;
    }

    return 0;
}