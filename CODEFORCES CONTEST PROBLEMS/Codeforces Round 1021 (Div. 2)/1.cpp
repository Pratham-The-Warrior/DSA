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

        string s;
        cin >> s;

        map<int, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i] - '0']++;
        }

        string ans = "";

        for (int i = 9; i >= 0; i--)
        {
            if (mp[i] > 0)
            {
                ans += to_string(i);
                mp[i]--;
            }
            else
            {
                int j = i;
                while (mp[j] == 0)
                {
                    j++;
                }
                ans += to_string(j);
                mp[j]--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
