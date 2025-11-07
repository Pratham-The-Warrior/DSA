/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;                      // number of cities
vector<vector<int>> dist;   // distance matrix
vector<vector<int>> dp;     // dp[mask][pos]
vector<vector<int>> parent; // to reconstruct the path

// Recursive TSP with path tracking
int tsp(int mask, int pos)
{
    if (mask == (1 << n) - 1) // all cities visited
        return dist[pos][0];  // return to start

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;
    int nextCity = -1;

    // Try all unvisited cities
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newCost < ans)
            {
                ans = newCost;
                nextCity = city;
            }
        }
    }

    parent[mask][pos] = nextCity; // store best next move
    return dp[mask][pos] = ans;
}

// Function to reconstruct the path
vector<int> getPath()
{
    vector<int> path;
    int mask = 1, pos = 0; // start at city 0
    path.push_back(0);

    while (true)
    {
        int nextCity = parent[mask][pos];
        if (nextCity == -1)
            break;
        path.push_back(nextCity);
        mask |= (1 << nextCity);
        pos = nextCity;
    }

    path.push_back(0); // return to start
    return path;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    dist.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    dp.assign(1 << n, vector<int>(n, -1));
    parent.assign(1 << n, vector<int>(n, -1));

    int minCost = tsp(1, 0);
    vector<int> path = getPath();

    cout << "\nMinimum travel cost: " << minCost << "\n";
    cout << "Optimal path: ";
    for (int city : path)
        cout << city << " ";
    cout << "\n";

    return 0;
}
