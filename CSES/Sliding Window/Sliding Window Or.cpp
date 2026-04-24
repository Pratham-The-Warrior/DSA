/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
You are given an array of n integers.
Your task is to calculate the bitwise or of each window of k elements, from left to right.

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

    ll ans = 0; // this will store xor of all OR od windows

    vector<int> pre(n), suf(n);

    return 0;
}