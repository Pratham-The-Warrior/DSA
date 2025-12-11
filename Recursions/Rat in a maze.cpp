/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

bool isSafe(int i, int j, int n)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

void solve(int i, int j, vector<vector<int>> &m, int n, string &path)
{
    if (!isSafe(i, j, n) || m[i][j] == 0)
        return;

    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(path);
        return;
    }

    m[i][j] = 0;

    path.push_back('D');
    solve(i + 1, j, m, n, path);
    path.pop_back();

    path.push_back('R');
    solve(i, j + 1, m, n, path);
    path.pop_back();

    path.push_back('L');
    solve(i, j - 1, m, n, path);
    path.pop_back();

    path.push_back('U');
    solve(i - 1, j, m, n, path);
    path.pop_back();

    m[i][j] = 1;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
    ans.clear();
    string path = "";
    int n = maze.size();

    if (maze[0][0] == 0)
        return ans;

    solve(0, 0, maze, n, path);
    sort(ans.begin(), ans.end());
    return ans;
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

        vector<vector<int>> maze(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> maze[i][j];

        vector<string> res = ratInMaze(maze);

        if (res.size() == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            for (auto &s : res)
                cout << s << " ";
            cout << "\n";
        }
    }

    return 0;
}
