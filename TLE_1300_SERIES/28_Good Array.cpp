/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long total = 0;
    for (long long x : a)
        total += x;

    // Get largest and second largest
    vector<long long> sorted = a;
    sort(sorted.begin(), sorted.end());

    long long mx = sorted[n - 1];
    long long secondMx = sorted[n - 2];

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        long long removed = a[i];

        long long newSum = total - removed;
        long long newLargest = (removed == mx ? secondMx : mx);

        if (newSum == 2 * newLargest)
            ans.push_back(i + 1);
    }

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}

/*******************************************************/
