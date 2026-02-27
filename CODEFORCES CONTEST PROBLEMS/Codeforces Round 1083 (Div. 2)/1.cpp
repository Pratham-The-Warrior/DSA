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
        vector<int> a(n);
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == n)
            {
                idx = i;
            }
        }

        swap(a[0], a[idx]);

        for (auto x : a)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}