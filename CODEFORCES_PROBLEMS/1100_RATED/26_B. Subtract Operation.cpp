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
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        set<long long> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }

        bool found = false;
        for (auto x : s)
        {
            if (s.find(x + k) != s.end() || s.find(x - k) != s.end())
            {
                found = true;
                break;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}