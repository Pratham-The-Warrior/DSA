/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if (k <= 1)
        return 0;

    int n = nums.size();
    int i = 0, j = 0;
    int current = 1;
    int ct = 0;

    while (j < n)
    {
        current *= nums[j];

        // shrink window until product < k
        while (current >= k && i <= j)
        {
            current /= nums[i];
            i++;
        }

        // count subarrays ending at j
        ct += (j - i + 1);

        j++;
    }
    return ct;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << numSubarrayProductLessThanK(a, k);
    }

    return 0;
}