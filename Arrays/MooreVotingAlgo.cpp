/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

// Function to find the candidate for majority element
int findCandidate(vector<int> &nums)
{
    int count = 0;
    int candidate = -1;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
            count = 1;
        }
        else if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

// Function to check if candidate is actually majority
bool isMajority(vector<int> &nums, int candidate)
{
    int count = 0;
    for (int num : nums)
    {
        if (num == candidate)
            count++;
    }
    return count > nums.size() / 2;
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
            cin >> nums[i];

        int candidate = findCandidate(nums);

        if (isMajority(nums, candidate))
        {
            cout << candidate << "\n";
        }
        else
        {
            cout << "No Majority Element\n";
        }
    }

    return 0;
}
