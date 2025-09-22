/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int i = s.size() - 2;

        while (i >= 0 && s[i] >= s[i + 1])
        {
            i--;
        }

        if (i < 0)
            return -1;

        // find just larger element than s[i]
        int j = s.size() - 1;
        while (j > i && s[j] <= s[i])
        {
            j--;
        }

        swap(s[i], s[j]);

        reverse(s.begin() + i + 1, s.end());

        long long ans = stoll(s);

        return (ans > INT_MAX) ? -1 : (int)ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    Solution solver;

    while (t--)
    {
        int n;
        cin >> n;
        cout << solver.nextGreaterElement(n) << "\n";
    }

    return 0;
}
