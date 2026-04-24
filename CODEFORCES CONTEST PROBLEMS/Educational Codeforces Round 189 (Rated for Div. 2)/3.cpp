#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;

        int count = 0;

        /*
        i think dynamic programming will be needed , looks similar..
        grredy may give wrong answers
        */

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {

            int vertical = (s1[i - 1] == s2[i - 1] ? 0 : 1);
            dp[i] = dp[i - 1] + vertical;

            if (i >= 2)
            {
                int row1 = (s1[i - 2] == s1[i - 1] ? 0 : 1);
                int row2 = (s2[i - 2] == s2[i - 1] ? 0 : 1);
                dp[i] = min(dp[i], dp[i - 2] + row1 + row2);
            }
        }

        cout << dp[n] << endl;
    }
}