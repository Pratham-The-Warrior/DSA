/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
You are given an array of n integers.
Your task is to calculate the number of
distinct values in each window of k elements,
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

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*
    maintain a map
    and use two pointers when shrinking window
    remove i.e decrese by 1 that a[l++] from map
    */
    map<ll, ll> mp;

    ll l = 0;

    for (ll r = 0; r < n; r++)
    {
        mp[a[r]]++;

        // shrink window if size > k
        if (r - l + 1 > k)
        {
            mp[a[l]]--;
            if (mp[a[l]] == 0)
                mp.erase(a[l]);
            l++;
        }

        if (r - l + 1 == k)
        {
            cout << mp.size() << " ";
        }
    }
    return 0;
}