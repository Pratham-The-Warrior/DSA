#include <bits/stdc++.h>
using namespace std;

// Calculate upper bound (fractional knapsack idea)
double bound(int i, int n, int W, vector<int> &value, vector<int> &weight, int profit, int w)
{
    if (w >= W)
        return 0;

    double profit_bound = profit;
    int totweight = w;

    while (i < n && totweight + weight[i] <= W)
    {
        totweight += weight[i];
        profit_bound += value[i];
        i++;
    }

    if (i < n)
        profit_bound += (W - totweight) * ((double)value[i] / weight[i]);

    return profit_bound;
}

// Branch and Bound
int knapsack(int n, int W, vector<int> &value, vector<int> &weight)
{
    // Sort items by value/weight ratio
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b)
         { return (double)value[a] / weight[a] > (double)value[b] / weight[b]; });

    queue<tuple<int, int, int>> q; // (level, profit, weight)
    q.push({0, 0, 0});
    int maxProfit = 0;

    while (!q.empty())
    {
        auto [i, profit, w] = q.front();
        q.pop();

        if (i == n)
            continue;

        // Take item i
        int newW = w + weight[idx[i]];
        int newP = profit + value[idx[i]];
        if (newW <= W && newP > maxProfit)
            maxProfit = newP;

        if (bound(i + 1, n, W, value, weight, newP, newW) > maxProfit)
            q.push({i + 1, newP, newW});

        // Do not take item i
        if (bound(i + 1, n, W, value, weight, profit, w) > maxProfit)
            q.push({i + 1, profit, w});
    }

    return maxProfit;
}

int main()
{
    vector<int> value = {16, 19, 23, 28};
    vector<int> weight = {2, 3, 4, 5};
    int W = 7;
    int n = value.size();

    cout << "Maximum profit = " << knapsack(n, W, value, weight) << endl;
    return 0;
}
