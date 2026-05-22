/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (auto c : dir)
    {
        int dx = c.first, dy = c.second;
        int nx = x + dx, ny = y + dy;

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (!visited[nx][ny] && grid[nx][ny] == '.')
            {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    int rooms = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j);
                rooms++;
                ;
            }
        }
    }

    cout << rooms;

    return 0;
}