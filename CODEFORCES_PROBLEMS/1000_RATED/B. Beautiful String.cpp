#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_palindrome(const string &s)
{
    if (s.empty())
        return true;
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

bool is_non_decreasing(const string &s)
{
    if (s.empty())
        return true;
    for (int i = 1; i < (int)s.length(); ++i)
    {
        if (s[i - 1] > s[i])
            return false;
    }
    return true;
}

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

        bool found = false;
        // O(2^N) BRUTE FORCE
        for (int m = 0; m < (1 << n); m++)
        {
            string p = "";
            string x = "";
            vector<int> p_idx;

            for (int i = 0; i < n; i++)
            {
                if ((m >> i) & 1) // If i-th bit is set, it goes to p
                {
                    p += s[i];
                    p_idx.push_back(i + 1);
                }
                else // Otherwise, it goes to x
                {
                    x += s[i];
                }
            }

            if (is_non_decreasing(p) && is_palindrome(x))
            {
                cout << p_idx.size() << "\n";
                for (int i = 0; i < (int)p_idx.size(); i++)
                {
                    cout << p_idx[i] << (i == (int)p_idx.size() - 1 ? "" : " ");
                }
                cout << "\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "-1" << "\n";
        }
    }

    return 0;
}

/****OPTIMIZED DP APPROACH****/

/*
The Core Idea: Two-Pointer DPA palindrome is naturally symmetric—the first character must match the last.
Therefore, we use two pointers, l (left) and r (right), to build the palindrome from the outside in.Simultaneously,
we need to ensure that any characters we "skip" (don't put in the palindrome) form a non-decreasing sequence $p$.
For binary strings, "non-decreasing" means you can't pick a 0 if you've already picked a 1.
*/
