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
        int n;
        cin >> n;
        string s;
        cin >> s;

        set<char> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            st.insert(s[i]);
            ans += st.size();
        }

        cout << ans << endl;
    }
    return 0;
}
