/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
This Problem can be solved using two ways :-
1. BFS solution
2. DP  solution
*/

vector<vector<int>> updateMatrixBFS(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                distance[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    // BFS starts from all zeros and spreads outward,
    // assigning the minimum distance to each 1.
    while (!q.empty())
    {

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && distance[nx][ny] == -1)
            {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return distance;
}

vector<vector<int>> updateMatrixDP(vector<vector<int>> &mat)
{

    /*
    as we have 4 directions to check but we can check 2 at a time using 2D DP
    so we will iterate two times first from top and left second time from bottom and right
    */
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 1e9)); // initize the dp matrix with MAX

    // case 1 from top and left

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                dp[i][j] = 0; // dist from 0 is 0
            }
            else
            {
                if (i > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // dp equation
                }
                if (j > 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
    }

    // case 2 from bottom and right

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (mat[i][j] == 0)
            {
                continue;
            }
            else
            {
                if (i < n - 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1); // dp equation
                }
                if (j < m - 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }
    }
    return dp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> ans;

    ans = updateMatrixDP(mat);
    ans = updateMatrixBFS(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}