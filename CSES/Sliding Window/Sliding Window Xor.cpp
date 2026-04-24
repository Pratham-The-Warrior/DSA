/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
You are given an array of n integers.
Your task is to calculate the bitwise xor of each window of k elements,
from left to right.
*/

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

    /*
    prefix xor of xor
    while taking prefix take xor and store that only

    can we use a xor property of
    px[r] ^ px[l-1]
    = (a[0] ^ ... ^ a[l-1] ^ a[l] ^ ... ^ a[r]) ^ (a[0] ^ ... ^ a[l-1])

= a[l] ^ ... ^ a[r]
    */

    // so calclulate prefix xor and store the results we need

    /*
    [0, k-1]
    [1, k]
    [2, k+1]
    ...
    [n-k, n-1]

    total => n - k + 1
    each window => nums[i], nums[i+1], ..., nums[i+k-1]
    to get XOR(i → j) => prefix[j] ^ prefix[i-1]
    */

    vector<ll> prefix(n, 0);

    prefix[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] ^ nums[i];
    }

    ll ans = 0;
    for (int i = 0; i <= n - k; i++)
    {
        ll windowXor;

        if (i == 0)
        {
            windowXor = prefix[k - 1];
        }
        else
        {
            windowXor = prefix[i + k - 1] ^ prefix[i - 1];
        }
        ans ^= windowXor;
    }

    cout << ans;

    return 0;
}