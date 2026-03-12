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

    string s;
    cin >> s;
    int n = s.size();

    vector<long long> pref(n + 1, 0), suff(n + 1, 0);

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1];
        if (s[i] == 'v' && s[i - 1] == 'v')
            pref[i]++;
    }
    pref[n] = pref[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1];
        if (s[i] == 'v' && s[i + 1] == 'v')
            suff[i]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'o')
            ans += pref[i] * suff[i];

    cout << ans << endl;
    return 0;
}
