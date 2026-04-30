/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
*PROBLEM STATEMENT
You are given an array of n integers.
Your task is to calculate the mode each window of k elements,
from left to right.The mode is the most frequent element in an array.
If there are several possible modes, choose the smallest of them.
*/

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
    for each window of size k
    to we have to get max occuring elemnt of that window

    take a map store elements in it
    when window comepletes remove count of
    left most element from map
    move ahead like l++
    and for each window
    pushback the key of most occuring freq value
    in ans vector
    */
    vector<ll> ans;
    map<ll, int> mp;

    int l = 0;

    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
        if (i - l + 1 >= k)
        {
            // find the most occuring freq val in map
            //  find the most occurring freq val in map
            int maxFreq = 0;
            long long val = LLONG_MAX;

            for (auto &p : mp)
            {
                if (p.second > maxFreq)
                {
                    maxFreq = p.second;
                    val = p.first;
                }
                else if (p.second == maxFreq)
                {
                    val = min(val, p.first);
                }
            }

            ans.push_back(val);

            mp[a[l]]--;
            if (mp[a[l]] == 0)
                mp.erase(a[l]);
            l++;
        }
    }

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}