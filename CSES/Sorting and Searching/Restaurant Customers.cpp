/*
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers in the restaurant at any time?
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Your code here
    // i have to find the largest intersection
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    /*
    2 1
    3 1
    4 -1
    5 1
    8 -1
    9 -1

    */

    sort(v.begin(), v.end());

    int curr = 0, ans = 0;

    for (auto x : v)
    {
        curr += x.second;
        ans = max(ans, curr);
    }

    cout << ans << endl;

    return 0;
}
//*--------------------------------------------------------------------------------------------*//
//*Variation 1. Weighted Interval Scheduling (Max Profit)

/*
    each interval => (start, end, profit)

    Sort intervals by end time
    For each interval i, find the last non-overlapping interval
    DP relation:

            dp[i] = max(dp[i-1],profit[i] + dp[last_non_overlap])

            struct Interval {
                int start, end, profit;
            };

            bool cmp(Interval a, Interval b) {
                return a.end < b.end;
            }

            int main() {
                int n;
                cin >> n;

                vector<Interval> arr(n);
                for (int i = 0; i < n; i++) {
                    cin >> arr[i].start >> arr[i].end >> arr[i].profit;
                }

                sort(arr.begin(), arr.end(), cmp);

                vector<int> dp(n);
                dp[0] = arr[0].profit;

                vector<int> ends;
                for (auto &x : arr) ends.push_back(x.end);

                for (int i = 1; i < n; i++) {
                    int include = arr[i].profit;

                    //* binary search
                    int j = upper_bound(ends.begin(), ends.end(), arr[i].start) - ends.begin() - 1;

                    if (j >= 0) include += dp[j];

                    dp[i] = max(dp[i-1], include);
                }

                cout << dp[n-1];
}

//*-----------------------------------------------------------------------------------------------------





*/