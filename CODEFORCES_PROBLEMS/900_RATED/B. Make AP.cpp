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

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        ll a, b, c;
        cin >> a >> b >> c;

        // multiply any one from a,b,c by m , m>0
        // and check if 2*b = a+c ,

        if (2 * b == a + c)
        {
            cout << "YES" << endl;
            continue;
            // already a AP
        }
        // lets

        if (2 * b > a + c)
        {
            // 2b = am +c
            // 2b = cm +a

            if ((2 * b) % a == c % a)
            {
                cout << "YES" << endl;
            }
            else if ((2 * b) % c == a % c)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            continue;
        }

        else
        {
            if ((a + c) % (2 * b) == 0)
            {
                // a+c =
                cout << "YES" << endl;
                continue;
            }
        }

        cout << "NO" << endl;
    }

    return 0;
}