#include <bits/stdc++.h>
using namespace std;

int n;                    // Number of cities
vector<vector<int>> dist; // Distance matrix
int final_res = INT_MAX;
vector<int> final_path;

// Function to copy current path to final path
void copyToFinal(vector<int> &curr_path)
{
    final_path = curr_path;
    final_path.push_back(curr_path[0]); // return to starting city
}

// Function to calculate lower bound for current node
int calculateBound(vector<int> &curr_path, vector<bool> &visited)
{
    int bound = 0;

    // Sum of minimum outgoing edges for all unvisited cities
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int min_edge = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    min_edge = min(min_edge, dist[i][j]);
            }
            bound += min_edge;
        }
    }
    return bound;
}

// Recursive Branch and Bound
void tspRec(vector<int> &curr_path, vector<bool> &visited, int curr_cost, int level)
{
    if (level == n)
    {
        // Add cost to return to starting city
        int total_cost = curr_cost + dist[curr_path[level - 1]][curr_path[0]];
        if (total_cost < final_res)
        {
            final_res = total_cost;
            copyToFinal(curr_path);
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int temp_cost = curr_cost + dist[curr_path[level - 1]][i];
            int temp_bound = temp_cost + calculateBound(curr_path, visited);
            if (temp_bound < final_res)
            { // Prune
                curr_path[level] = i;
                visited[i] = true;
                tspRec(curr_path, visited, temp_cost, level + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    // Example distance matrix
    dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};
    n = dist.size();

    vector<int> curr_path(n);
    vector<bool> visited(n, false);

    curr_path[0] = 0; // Start from city 0
    visited[0] = true;

    tspRec(curr_path, visited, 0, 1);

    cout << "Minimum cost = " << final_res << endl;
    cout << "Path: ";
    for (int i : final_path)
        cout << i << " ";
    cout << endl;

    return 0;
}
