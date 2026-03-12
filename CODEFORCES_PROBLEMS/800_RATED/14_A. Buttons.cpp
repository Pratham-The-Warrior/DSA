/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
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
        // anna first
        int a, b, c;
        cin >> a >> b >> c;

        if (a > b)
        {
            cout << "First" << endl;
        }
        else if (a == b)
        {
            if (c % 2 != 0)
            {
                cout << "First" << endl;
            }
            else
            {
                cout << "Second" << endl;
            }
        }
        else
        {
            cout << "Second" << endl;
        }
    }

    return 0;
}