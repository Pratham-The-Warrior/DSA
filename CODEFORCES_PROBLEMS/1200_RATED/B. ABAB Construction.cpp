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

    /* ====================================

    abababab


    abbaa

    aabab
    bb

    aa_b_b
    ababab

    abbaa

    odd case
    abababa

    aabbaa  (2,3) (3,4) ... can`t be same

    even case
    ababab  (1,2) (3,4)...can`t be same
    abbaab




     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool ok = true;

        if (n % 2 == 1)
        {

            if (s[0] == 'b')
                ok = false;

            // Check pairs (2,3), (4,5), ...
            for (int i = 1; i + 1 < n; i += 2)
            {
                if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1])
                {
                    ok = false;
                    break;
                }
            }
        }
        else
        {
            // Check pairs (1,2), (3,4), ...
            for (int i = 0; i + 1 < n; i += 2)
            {
                if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1])
                {
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}