/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

        vector<int> pos;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {

                pos.push_back(i);
            }
        }

        int m = pos.size();
        if (m == 0)
        {
            cout << 0 << endl;
            continue;
        }

        int median = m / 2;

        int median_pos = pos[median];

        ll ans = 0;

        for (int i = 0; i < m; i++)
        {
            ans += abs(pos[i] - (median_pos - median + i));
        }

        cout << ans << endl;
    }

    return 0;
}

/*
1 3 7 9 10
*/