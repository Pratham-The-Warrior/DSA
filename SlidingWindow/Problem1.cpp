/*
Problem-Statement
The DNA sequence is composed of a series of nucleotides
abbreviated as 'A', 'C', 'G', and 'T'.
For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.
Given a string s that represents a DNA sequence, return all the 10-letter-long
sequences (substrings) that occur more than once in a DNA molecule.
You may return the answer in any order.*/

/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
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
        string s;
        cin >> s;

        vector<string> ans;
        unordered_map<string, int> m;
        int n = s.size();

        for (int i = 0; i < n - 9; i++)
        {
            string temp = "";
            int c = 0, j = 0;
            while (c < 10)
            {
                temp += s[i + j];
                c++;
                j++;
            }
            m[temp]++;
        }

        for (auto x : m)
        {
            if (x.second > 1)
            {
                ans.push_back(x.first);
            }
        }

        for (const string &seq : ans)
        {
            cout << seq << '\n';
        }
    }

    return 0;
}
