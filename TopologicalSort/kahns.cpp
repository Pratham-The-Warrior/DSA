/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
*Kahn's Algorithm is a graph algorithm used to find a topological ordering of a Directed Acyclic Graph (DAG).
A topological order is a linear ordering of vertices such that for every directed edge u → v, vertex u appears before v.

*Kahn's algorithm repeatedly:
Finds nodes with no incoming edges (in-degree = 0).
Adds them to the result.
Removes their outgoing edges.
Updates in-degrees.
Repeats until no nodes remain.
*/

vector<int> kahn(int n, vector<vector<int>> &adj)
{

    vector<int> indeg(n, 0);

    for (int u = 0; u < n; u++)
    {
        for (auto v : adj[u])
        {
            indeg[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (auto v : adj[u])
        {
            indeg[v]--; // update indegree
            if (indeg[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return topo;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
    }

    return 0;
}