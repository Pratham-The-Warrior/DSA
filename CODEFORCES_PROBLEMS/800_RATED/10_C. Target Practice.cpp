/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> board(11, vector<int>(11, 0));

void precompute()
{

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
            board[i][j] = 0;

    // outer ring
    for (int i = 1; i <= 10; i++)
    {
        board[i][1] = 1;
        board[i][10] = 1;
    }

    for (int i = 1; i <= 10; i++)
    {
        board[1][i] = 1;
        board[10][i] = 1;
    }

    // 2nd ring

    for (int i = 2; i <= 9; i++)
    {
        board[i][2] = 2;
        board[i][9] = 2;
    }

    for (int i = 2; i <= 9; i++)
    {
        board[2][i] = 2;
        board[9][i] = 2;
    }

    // 3rd ring

    for (int i = 3; i <= 8; i++)
    {
        board[i][3] = 3;
        board[i][8] = 3;
    }

    for (int i = 3; i <= 8; i++)
    {
        board[3][i] = 3;
        board[8][i] = 3;
    }

    // 4th ring

    for (int i = 4; i <= 7; i++)
    {
        board[i][4] = 4;
        board[i][7] = 4;
    }

    for (int i = 4; i <= 7; i++)
    {
        board[4][i] = 4;
        board[7][i] = 4;
    }
    for (int i = 5; i <= 6; i++)
    {
        board[i][5] = 5;
        board[i][6] = 5;
    }

    for (int i = 5; i <= 6; i++)
    {
        board[5][i] = 5;
        board[6][i] = 5;
    }
}
int check(int i, int j)
{
    return board[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> v(11, vector<char>(11));

        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                cin >> v[i][j];
            }
        }

        int ans = 0;

        for (int i = 1; i <= 10; i++)
        {
            for (int j = 1; j <= 10; j++)
            {
                if (v[i][j] == 'X')
                    ans += check(i, j);
            }
        }
        cout << ans << endl;
    }

    return 0;
}