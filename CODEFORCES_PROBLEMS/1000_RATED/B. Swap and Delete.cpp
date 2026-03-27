/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int ct0 = count(s.begin(), s.end(), '0');
        int ct1 = count(s.begin(), s.end(), '1');

        int len = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (ct1 > 0)
                {
                    ct1--;
                    len++;
                }
                else
                    break;
            }
            else
            {
                if (ct0 > 0)
                {
                    ct0--;
                    len++;
                }
                else
                    break;
            }
        }

        cout << (int)s.size() - len << endl;
    }

    return 0;
}