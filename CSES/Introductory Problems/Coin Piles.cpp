/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
You have two coin piles containing a and b coins.
On each move, you can either remove one coin from
the left pile and two coins from the right pile,
or two coins from the left pile and one coin from
the right pile.Your task is to efficiently find out
if you can empty both the piles.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    /*
    5 6 => 4 4
    3 5 => 2 3 => 1 2
    1 6
    */

    // NO will be when either one of them is greater thatn 2 times that of smaller one
    /*
    2 1 , 1 2 => every step -3
    */

    while (n--)
    {
        ll x, y;
        cin >> x >> y;

        if (max(x, y) > 2 * min(x, y) || (x + y) % 3 != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}