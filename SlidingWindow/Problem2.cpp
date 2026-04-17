#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
*Given an array a of size n.
*A subarray is called "good" if there exists at least one element
*that appears exactly once in that subarray.

*Otherwise, the subarray is "bad" (i.e., every element appears either 0 times or at least 2 times).

*Task:Find the length of the longest bad subarray.

*Constraints:
*- Multiple test cases
*- 1 ≤ n ≤ ~500 (or higher depending on version)
*/

bool isBad(vector<int> &a, int l, int r)
{
    unordered_map<int, int> freq;

    for (int i = l; i <= r; i++)
    {
        freq[a[i]]++;
    }

    for (auto &p : freq)
    {
        if (p.second == 1)
            return false;
    }

    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        //*--------------------------------approach1 O(n^3)---------------------------------------*//

        /*
        one approach i think is bruteforce generate all bad arrays , store intervals
        greedily find least positions such that all get good
        */

        //     vector<pair<int, int>> intervals;

        //     for (int l = 0; l < n; l++)
        //     {
        //         for (int r = l; r < n; r++)
        //         {
        //             if (isBad(a, l, r))
        //             {
        //                 intervals.push_back({l, r});
        //             }
        //         }
        //     }

        //     sort(intervals.begin(), intervals.end(), [](auto &p1, auto &p2)
        //          {
        //              return p1.second < p2.second; // put p1 before p2 if this is true
        //          });

        //     // find minimum points

        //     int last = -1;
        //     int ans = 0;

        //     for (auto x : intervals)
        //     {
        //         int l = x.first;
        //         int r = x.second;
        //         if (last < l)
        //         {
        //             ans++;
        //             last = r;
        //         }
        //     }
        //     cout << ans << endl;
        // }

        //*--------------------------------O(n^2) Approach--------------------------------------*//
        //
        vector<pair<int, int>> bad;
        for (int i = 0; i < n; i++)
        {
            vector<int> freq(n + 1, 0);
            int unique_cnt = 0;
            for (int j = i; j < n; j++)
            {
                if (++freq[a[j]] == 1)
                    unique_cnt++;
                else if (freq[a[j]] == 2)
                    unique_cnt--;

                // If no element appears exactly once, it's a bad interval
                if (unique_cnt == 0)
                    bad.push_back({j, i}); // {end, start}
            }
        }

        sort(bad.begin(), bad.end()); // Sorts by end-point 'j'

        int ans = 0, last_change = -1;
        for (auto &p : bad)
        {
            // If the start of this bad interval is after our last change
            if (p.second > last_change)
            {
                ans++;
                last_change = p.first; // Change the element at the end of the interval
            }
        }
        cout << ans << endl;
    }
    return 0;
}