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
        string s;
        cin >> s;
        set<char> st;
        for (auto c : s)
            st.insert(c);

        int k = st.size();
        bool ok = true;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != s[i % k])
            {
                ok = false;
                break;
            }
        }

        if (ok)
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