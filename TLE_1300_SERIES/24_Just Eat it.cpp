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

        long long n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long total = accumulate(a.begin(), a.end(), 0LL);

        // Kadane algo
        long long curr = 0, max_pref = LLONG_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            curr += a[i];
            max_pref = max(max_pref, curr);
            if (curr < 0)
                curr = 0;
        }

        curr = 0;
        long long max_suf = LLONG_MIN;
        for (int i = 1; i < n; i++)
        {
            curr += a[i];
            max_suf = max(max_suf, curr);
            if (curr < 0)
                curr = 0;
        }

        if (max_pref >= total || max_suf >= total)
            cout << "NO";
        else
            cout << "YES";

        cout << endl;
    }

    return 0;
}
