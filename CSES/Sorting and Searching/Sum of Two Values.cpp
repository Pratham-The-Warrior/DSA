/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
You are given an array of n integers, and your task is to find two values
(at distinct positions) whose sum is x.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        ll need = x - a[i];

        if (mp.count(need))
        {
            cout << mp[need] + 1 << " " << i + 1;
            return 0;
        }

        mp[a[i]] = i;
    }

    cout << "IMPOSSIBLE";
    return 0;
}