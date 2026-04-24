/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
You are given an array of n integers.
Your task is to calculate the sum of each window of k elements, from left to right.
Print the xor of all window sums.
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

    vector<ll> num(n);

    num[0] = x;

    for (int i = 1; i < n; i++)
    {
        num[i] = (a * num[i - 1] + b) % c;
    }

    // now we have got the vector

    ll ans = 0;

    // Prefix sum
    vector<ll> pref(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + num[i];
    }

    for (int i = 0; i + k <= n; i++)
    {
        ll window_sum = pref[i + k] - pref[i];

        ans ^= window_sum;
    }
    cout << ans;
}