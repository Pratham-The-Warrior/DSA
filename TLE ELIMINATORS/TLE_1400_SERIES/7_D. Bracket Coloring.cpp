#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Condition 1: Must have equal number of brackets
    if (count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')'))
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans(n);
    int balance = 0;
    int current_color = 0;

    for (int i = 0; i < n; i++)
    {
        if (balance == 0)
        {
            // Start a new balanced segment
            // If it starts with '(', it's a forward-balanced segment (Color 1)
            // If it starts with ')', it's a backward-balanced segment (Color 2)
            current_color = (s[i] == '(' ? 1 : 2);
        }

        ans[i] = current_color;

        if (s[i] == '(')
            balance++;
        else
            balance--;
    }

    set<int> unique_colors(ans.begin(), ans.end());

    if (unique_colors.size() == 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
    }
    else
    {
        cout << 2 << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}