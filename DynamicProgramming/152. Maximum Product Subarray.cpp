/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

// NAIVE BRUTE FORCE
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int ans = 1;
        for (int j = i; j < n; j++)
        {
            ans *= nums[j];
            maxi = max(maxi, ans);
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
    }

    return 0;
}