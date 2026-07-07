/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
}

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int target = nums.size() - k;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int pivot = nums[right];
            int fill = left;

            for (int i = left; i < right; i++)
            {
                if (nums[i] <= pivot)
                {
                    swap(nums[fill], nums[i]);
                    fill++;
                }
            }

            swap(nums[fill], nums[right]);

            if (fill == target)
            {
                return nums[fill];
            }
            else if (fill < target)
            {
                left = fill + 1;
            }
            else
            {
                right = fill - 1;
            }
        }
        return -1;
    }
};