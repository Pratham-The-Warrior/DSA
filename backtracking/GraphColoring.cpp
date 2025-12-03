#include <bits/stdc++.h>
using namespace std;

// Function to check if vertex v can be assigned color c
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &color, int c)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[v][i] && color[i] == c)
            return false; // adjacent vertex has same color
    }
    return true;
}

// Recursive function to solve graph coloring
bool graphColoringUtil(vector<vector<int>> &graph, int m, vector<int> &color, int v)
{
    int n = graph.size();
    if (v == n)
        return true; // all vertices colored

    for (int c = 1; c <= m; c++)
    { // try all colors
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; // backtrack
        }
    }
    return false;
}

// Function to solve the Graph Coloring Problem
bool graphColoring(vector<vector<int>> &graph, int m)
{
    int n = graph.size();
    vector<int> color(n, 0);
    if (!graphColoringUtil(graph, m, color, 0))
    {
        cout << "No solution exists\n";
        return false;
    }

    cout << "Solution exists. Vertex colors:\n";
    for (int i = 0; i < n; i++)
        cout << "Vertex " << i << " -> Color " << color[i] << "\n";
    return true;
}

int main()
{
    // Example graph (adjacency matrix)
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}};
    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
