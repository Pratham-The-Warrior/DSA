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

        int ans = 0, ct = 0;

        for (int i = 0; i < n; i += 2)
        {
            if (s[i] == '#')
            {
                ct++;
            }
        }

        int need = (n + 1) / 2;

        cout << need - ct << endl;
    }

    return 0;
}