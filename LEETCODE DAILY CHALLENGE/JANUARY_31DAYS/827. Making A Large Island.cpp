/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    static constexpr int directions[4][2] = {
        {1, 0},  // down
        {-1, 0}, // up
        {0, 1},  // right
        {0, -1}  // left
    };

public:
    int exploreIsland(vector<vector<int>> &grid, int id, int row, int col)
    {
        if ((row < 0 || row >= grid.size()) ||
            ((col < 0 || col >= grid[0].size()) || (grid[row][col] != 1)))
        {
            return 0;
        }
        grid[row][col] = id;
        int size = 1;

        for (auto &dir : directions)
        {
            size += exploreIsland(grid, id, row + dir[0], col + dir[1]);
        }
        return size;
    }

    int largestIsland(vector<vector<int>> &grid)
    {

        unordered_map<int, int> islandSizes;
        int id = 2;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    islandSizes[id] = exploreIsland(grid, id, i, j);
                    ++id;
                }
            }
        }

        if (islandSizes.empty())
        {
            return 1;
        }

        if (islandSizes.size() == 1)
        {
            id--;
            return (islandSizes[id] == grid.size() * grid[0].size())
                       ? islandSizes[id]      // no 0 there
                       : islandSizes[id] + 1; // 0 take
        }

        int maxi = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    int currLandSize = 1;
                    set<int> neighbors;

                    for (auto &dir : directions)
                    {
                        int newR = i + dir[0];
                        int newC = j + dir[1];

                        if (newR >= 0 && newR < grid.size() && newC >= 0 &&
                            newC < grid[0].size() && grid[newR][newC] != 0)
                        {
                            neighbors.insert(grid[newR][newC]);
                        }
                    }
                    for (int id : neighbors)
                    {
                        currLandSize += islandSizes[id];
                    }

                    maxi = max(maxi, currLandSize);
                }
            }
        }
        return maxi;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}