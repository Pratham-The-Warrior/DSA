/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> nums(n);
    nums[0] = x;

    for (int i = 1; i < n; i++)
    {
        nums[i] = (a * nums[i - 1] + b) % c;
    }

    // vector<ll>pref(n+1,0); //this will store the minimum value till that point
    // in this problem as we need minimum values of a range
    // deque will be useful O(n) time
    // We maintain a deque that stores indices, and it always keeps elements in increasing order of values.
    // So:The front of the deque = index of the minimum element for the current window We remove useless elements as we go

    deque<int> dq; // stores indices
    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        // Remove indices that are out of this window
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // Maintain increasing order in deque
        while (!dq.empty() && nums[dq.back()] >= nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        // Window is ready
        if (i >= k - 1)
        {
            res.push_back(nums[dq.front()]);
        }
    }

    ll ans = 0;

    for (auto x : res)
    {
        ans ^= x;
    }

    cout << ans;
}