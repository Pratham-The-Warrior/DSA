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
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (s[0] == 'B')
        {
            if (s[n - 1] == 'B')
            {
                cout << "Bob" << endl;
            }
            else if (s[n - 2] == 'B')
            {
                cout << "Bob" << endl;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
        else
        {
            int ct = 0;

            ct = count(s.begin(), s.end(), 'B');

            if (ct == 1 && s[n - 1] == 'B')
            {
                cout << "Alice" << endl;
            }
            else if (s[n - 1] == 'B') // as ct>1 we can take care if alice throws card 1 to takle nth card
            {
                cout << "Bob" << endl;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
    }

    return 0;
}