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

    string s;
    cin >> s;
    int n = s.size();
    int ct = 1, ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            ct++;
        }
        else
        {
            ans = max(ct, ans);
            ct = 1;
        }
    }
    ans = max(ct, ans);

    cout << ans << endl;

    // find the

    return 0;
}