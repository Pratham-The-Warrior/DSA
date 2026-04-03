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

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    /* ====================================
       LOGIC / OBSERVATIONS:
        i have to divide numbers into two sequnces
        if mp[element] odd => +1
        if mp[element] even => depends on cases
       ==================================== */

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        vector<int> a(n * 2);
        map<int, int> mp;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        int ans = 0, cntodd = 0;

        for (auto x : mp)
        {
            if (x.second & 1)
            { // odd frequency
                ans++;
                cntodd++;
            }
        }

        int cnt = 0;

        for (auto x : mp)
        {
            if (x.second % 2 == 0)
            {
                if (x.second % 4 == 2)
                {
                    ans += 2; // case in which freq is even and freq/2 is odd element basically number not didsible by 4
                }
                else
                {
                    cnt++; // count number of such freq of form 4*K
                }
            }
        }

        if (cntodd == 0)
        {
            if (cnt % 2 == 0)
            {
                cout << ans + 2 * (cnt) << endl;
            }
            else
            {
                cout << ans + 2 * (cnt - 1) << endl; // one of freq wont contribute
            }
        }
        else
        {
            cout << ans + cnt * 2 << endl;
        }
    }

    return 0;
}