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

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            p[i] = {a[i], i}; // Store value and original index
        }

        // Sort based on values
        sort(p.begin(), p.end(), [](const auto &a, const auto &b)
             { return a.first < b.first; });

        int i = 0, j = n - 1;
        pair<int, int> ans = {-1, -1};

        while (i < j)
        {
            int sum = p[i].first + p[j].first;

            if (sum == k)
            {
                ans = {p[i].second, p[j].second};
                break;
            }
            else if (sum < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        if (ans.first == -1)
            cout << "No such pair\n";
        else
            cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
