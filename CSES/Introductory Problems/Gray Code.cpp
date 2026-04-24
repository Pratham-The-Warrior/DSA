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

    int n;
    cin >> n;

    int limit = (1 << n);

    for (int i = 0; i < limit; i++)
    {
        int gray = i ^ (i >> 1);

        for (int j = 0; j < n; j++)
        {
            cout << ((gray >> j) & 1);
        }
        cout << endl;
    }

    return 0;
}