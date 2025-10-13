/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void checkBalanced(const string &s, int &maxLen, int type)
{
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = -1;

    int ca = 0, cb = 0, cc = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'a')
            ca++;
        else if (s[i] == 'b')
            cb++;
        else
            cc++;

        pair<int, int> curr;

        switch (type)
        {
        case 1:
            curr = {ca - cb, cb - cc};
            break; // a,b,c all balanced
        case 2:
            curr = {ca - cb, cc};
            break; // a,b balanced
        case 3:
            curr = {ca - cc, cb};
            break; // a,c balanced
        case 4:
            curr = {cb - cc, ca};
            break; // b,c balanced
        case 5:
            curr = {cb, cc};
            break; // only a
        case 6:
            curr = {ca, cc};
            break; // only b
        case 7:
            curr = {ca, cb};
            break; // only c
        }

        if (mp.count(curr))
        {
            maxLen = max(maxLen, i - mp[curr]);
        }
        else
        {
            mp[curr] = i;
        }
    }
}

int longestBalanced(string s)
{
    int maxLen = 0;

    for (int type = 1; type <= 7; ++type)
        checkBalanced(s, maxLen, type);

    return maxLen;
}

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
        cout << longestBalanced(s) << endl;
        ;
    }

    return 0;
}
