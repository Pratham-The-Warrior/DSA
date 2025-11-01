#include <iostream>
#include <vector>
using namespace std;

void printCycle(const vector<int> &path)
{
    for (int v : path)
        cout << v << " -> ";
    cout << path[0] << endl;
}

bool isSafe(int v, const vector<vector<int>> &graph, const vector<int> &path, int pos)
{
    if (!graph[path[pos - 1]][v])
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

void solveAll(const vector<vector<int>> &graph, vector<int> &path, int pos, bool &found)
{
    int V = graph.size();
    if (pos == V)
    {
        if (graph[path[pos - 1]][path[0]])
        {
            printCycle(path);
            found = true;
        }
        return;
    }
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            solveAll(graph, path, pos + 1, found);
            path[pos] = -1;
        }
    }
}

void findAllHamiltonianCycles(const vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> path(V, -1);
    path[0] = 0;
    bool found = false;
    cout << "\nHamiltonian Cycles found:\n";
    solveAll(graph, path, 1, found);
    if (!found)
        cout << "No Hamiltonian Cycle exists\n";
}

int main()
{
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];
    findAllHamiltonianCycles(graph);
}
