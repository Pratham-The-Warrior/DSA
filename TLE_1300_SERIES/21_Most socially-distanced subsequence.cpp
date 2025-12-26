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
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<int> s;
        s.push_back(p[0]);

        for (int i = 1; i < n - 1; i++)
        {
            if ((p[i] > p[i - 1] && p[i] > p[i + 1]) ||
                (p[i] < p[i - 1] && p[i] < p[i + 1]))
            {
                s.push_back(p[i]);
            }
        }

        s.push_back(p[n - 1]);

        cout << s.size() << "\n";
        for (int x : s)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
