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

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> pos(51, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (pos[a[i]] == 0)
            pos[a[i]] = i; // first occurrence
    }

    while (q--)
    {
        int t;
        cin >> t;

        cout << pos[t] << " ";

        for (int i = 1; i < 51; i++)
        {
            if (pos[i] < pos[t])
            {
                pos[i] = pos[i] + 1; // shift by 1
            }
        }

        pos[t] = 1;
    }

    return 0;
}