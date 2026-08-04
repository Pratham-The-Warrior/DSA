/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
 *CSES Problem Set-Round Trip*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;

// Stores the parent of every node during DFS
// Used later to reconstruct the cycle path
vector<int> color, parent;
// color[i] tells the state of node i:
// 0 -> node is not visited
// 1 -> node is currently inside DFS recursion stack
// 2 -> node has been completely explored
vector<int> cycle;


bool dfs(int node,int par){

      color[node] = 1;

      for(auto nxt:adj[node]){

        if(nxt==par){
            continue;
        }

        if(color[nxt]==0){
            parent[nxt]=node;

            if(dfs(nxt,node)){
                return true;
            }

        }
        else if(color[nxt]==1){
            
        }
      }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // goes through two or more distinct cities and returns
    // so do a bfs from each city check if we can reach strat again from that route
    // if we can reconstruct tha path using parent vector

    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);



    return 0;
}