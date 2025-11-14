/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

double greedyKnapsack(vector<int> weight, vector<int> value, int capacity)
{
    int n = weight.size();
    vector<pair<double, int>> ratio(n);

    for (int i = 0; i < n; i++)
        ratio[i] = {(double)value[i] / weight[i], i};

    sort(ratio.rbegin(), ratio.rend());

    double maxProfit = 0.0;

    for (auto &p : ratio)
    {
        int idx = p.second;

        if (capacity >= weight[idx])
        {
            capacity -= weight[idx];
            maxProfit += value[idx];
        }
        else
        {
            // take fractional part
            maxProfit += p.first * capacity;
            break;
        }
    }

    return maxProfit;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, cap;
        cin >> n >> cap;

        vector<int> weight(n), value(n);

        for (int i = 0; i < n; i++)
            cin >> weight[i];

        for (int i = 0; i < n; i++)
            cin >> value[i];

        double ans = greedyKnapsack(weight, value, cap);

        cout << fixed << setprecision(3) << ans << "\n";
    }

    return 0;
}
