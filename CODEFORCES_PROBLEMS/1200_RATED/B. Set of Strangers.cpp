/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/
/*
*PROBLEM STATEMENT
In one step, you can choose any set of strangers such that all cells in it have the same color
and paint all of them in some other color. You can choose the resulting color.

What is the minimum number of steps you need to make the whole table the same color?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    i have to make everyone same
    i think since
    i think forst i should calculate the stranger set of each number
    like how many distinct groups a particular number has like how many steps will it need => may be i can use dfs for this
    find the size of largest island that will be max step need but this may not work i need to find better way to get how much a particular num will need
    store all of these in a map
    then iterate over the map
    for a particulr number ans = min(ans,sum(map.second)-map[key]) all steps values except the current key ones as they are already same
    return min

    5 5 5
    5 5 5
    5   5

    */

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        set<int> unique;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                unique.insert(grid[i][j]);
            }
        }

        if (unique.size() <= 1)
        {
            cout << 0 << "\n";
            continue;
        }

        set<int> has_adjacent;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // right neighbor
                if (j + 1 < m && grid[i][j] == grid[i][j + 1])
                {
                    has_adjacent.insert(grid[i][j]);
                }
                // down neighbor
                if (i + 1 < n && grid[i][j] == grid[i + 1][j])
                {
                    has_adjacent.insert(grid[i][j]);
                }
            }
        }

        int total_cost = 0;
        int max_cost = 0;

        for (int color : unique)
        {
            int cost = (has_adjacent.count(color)) ? 2 : 1;
            total_cost += cost;
            max_cost = max(max_cost, cost);
        }

        cout << total_cost - max_cost << "\n";
    }

    return 0;
}