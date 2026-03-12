/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string s2, string temp)
{

    // check if temp is a substring of s2
    return s2.find(temp) != string::npos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;

        if (s1 == s2)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = -1;
        string temp = s1;
        for (int i = 0; i <= 10; i++)
        {
            if (check(temp, s2))
            {
                ans = i;
                break;
            }
            temp = temp + s1;
            s1 = temp;
        }

        cout << ans << endl;
    }

    return 0;
}