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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int pairs_need = (n - k) / 2;

        map<char, int> mp;

        for (auto c : s)
            mp[c]++;
        int cnt = 0;

        for (auto x : mp)
        {
            cnt += x.second / 2;
        }

        cout << (pairs_need <= cnt ? "YES" : "NO") << endl;
    }

    return 0;
}