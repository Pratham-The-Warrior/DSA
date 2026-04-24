/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Given a string, your task is to reorder its letters in such a way
that it becomes a palindrome (i.e., it reads the same forwards and backwards).
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();

    map<char, int> mp;

    for (auto c : s)
    {
        mp[c]++;
    }

    int odd = 0;

    for (auto x : mp)
    {
        if (x.second % 2 != 0)
        {
            odd++;
        }
        if (odd > 1)
        {
            cout << "NO SOLUTION";
            return 0;
        }
    }

    vector<char> ans(n + 1, '#');
    char mid;
    int i = 1;
    for (auto x : mp)
    {
        int cnt = x.second;

        while (cnt >= 2)
        {
            ans[i] = x.first;
            ans[n - i + 1] = x.first;
            i++;
            cnt -= 2;
        }

        if (cnt == 1)
        {
            ans[(n + 1) / 2] = x.first;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }

    return 0;
}