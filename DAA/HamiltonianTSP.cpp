/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void tspHamiltonianCycle(const vector<vector<int>> &graph, vector<bool> &visited, int currentPos, int count, int cost, int &minCost)
{
    int n = graph.size();

    if (count == n && graph[currentPos][0] > 0)
    {
        minCost = min(minCost, cost + graph[currentPos][0]);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[currentPos][i] > 0)
        {
            visited[i] = true;
            tspHamiltonianCycle(graph, visited, i, count + 1, cost + graph[currentPos][i], minCost);
            visited[i] = false; // backtrack
        }
    }
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

        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }

        vector<bool> visited(n, false);
        visited[0] = true;

        int minCost = INT_MAX;

        tspHamiltonianCycle(graph, visited, 0, 1, 0, minCost);

        cout << minCost << "\n";
    }

    return 0;
}
