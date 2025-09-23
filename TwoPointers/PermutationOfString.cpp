/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if (n > m)
        return false;

    vector<int> freq1(26, 0);
    for (char c : s1)
    {
        freq1[c - 'a']++;
    }

    for (int i = 0; i <= m - n; i++)
    {
        string temp = s2.substr(i, n);

        vector<int> freq2(26, 0);
        for (char c : temp)
        {
            freq2[c - 'a']++;
        }

        if (freq1 == freq2)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << (checkInclusion(s1, s2) ? "true" : "false") << endl;
    }

    return 0;
}