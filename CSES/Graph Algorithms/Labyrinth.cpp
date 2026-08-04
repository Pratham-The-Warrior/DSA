/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);

    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> move(n, vector<char>(m));

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] != '#')
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
                parent[nx][ny] = {x, y};
                move[nx][ny] = dir[k];
            }
        }
    }

    if (!vis[end.first][end.second])
    {
        cout << "NO";
        return 0;
    }

    cout << "YES" << "\n";

    string path;

    pair<int, int> cur = end;

    while (cur != start)
    {
        path += move[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    cout << path;

    return 0;
}