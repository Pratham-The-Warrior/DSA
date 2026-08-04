#include <bits/stdc++.h>
using namespace std;

string s, cur;
bool used[8];
set<string> ans;

void brute()
{
    if (cur.size() == s.size())
    {
        ans.insert(cur);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            cur += s[i];

            brute();

            cur.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    cin >> s;

    brute();

    cout << ans.size() << "\n";
    for (auto &x : ans)
        cout << x << "\n";
}