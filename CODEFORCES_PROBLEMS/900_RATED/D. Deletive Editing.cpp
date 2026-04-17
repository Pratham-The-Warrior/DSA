/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

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
        string a, b;
        cin >> a >> b;
        map<char, int> mp;

        for (auto c : b)
        {
            mp[c]++;
        }

        string ans = "";

        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (mp[a[i]] > 0)
            {
                ans += a[i];
                mp[a[i]]--;
            }
        }

        reverse(ans.begin(), ans.end());

        if (ans == b)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}