/*-------------------------------------------------------------
    NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
TIP: when a question asks for a path, check if we can do it
using backtracking (path reconstruction problem).

from (2^k, 2^k) => (x, 2^k+1-x)
there will only be one path

intermediate form: (2x-2^k+1, 2x) depending on value we will give ops type
depending on the value of x there is only one path that exist...
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll k, x;
        cin >> k >> x;

        vector<int> ans;

        // backtracking loop
        ll y = (1LL << (k + 1)) - x;
        while (x != y)
        {
            if (x < y)
            {
                y -= x;
                x *= 2;
                ans.push_back(1);
            }
            else
            {
                x -= y;
                y *= 2;
                ans.push_back(2);
            }
        }

        /*
        Operation 1: (x, y) -> (2x, y-x)
        Operation 2: (x, y) -> (x-y, 2y)

        To backtrack, we look at the current values of x and y:
        If x < y: In the forward direction, the last move must have been Operation 1
        because x was "smaller" and got doubled, while y was "larger" and had x subtracted from it.
        */

        reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}