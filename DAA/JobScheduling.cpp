/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool cmpPair(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second; // sort by profit desc
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        vector<int> id(n), deadline(n), profit(n);
        for (int i = 0; i < n; i++)
        {
            cin >> id[i] >> deadline[i] >> profit[i];
        }

        // Make sortable pairs (index, profit)
        vector<pair<int, int>> order;
        for (int i = 0; i < n; i++)
        {
            order.push_back({i, profit[i]});
        }

        sort(order.begin(), order.end(), cmpPair);

        int maxDead = 0;
        for (int d : deadline)
            maxDead = max(maxDead, d);

        vector<int> slot(maxDead + 1, -1);

        int totalProfit = 0, countJobs = 0;

        for (auto &p : order)
        {
            int i = p.first; // job index

            for (int d = deadline[i]; d > 0; d--)
            {
                if (slot[d] == -1)
                {
                    slot[d] = id[i];
                    totalProfit += profit[i];
                    countJobs++;
                    break;
                }
            }
        }

        cout << countJobs << " " << totalProfit << "\n";
    }

    return 0;
}
