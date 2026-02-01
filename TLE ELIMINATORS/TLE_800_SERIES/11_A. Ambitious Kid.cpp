/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M      *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    int mini_pos = INT_MAX; // smallest positive
    int max_neg = INT_MIN;  // largest negative (closest to zero)
    bool zero = false;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        if (a[i] == 0)
            zero = true;
        else if (a[i] > 0)
            mini_pos = min(mini_pos, a[i]);
        else
            max_neg = max(max_neg, a[i]);
    }

    if (zero)
    {
        cout << 0 << endl;
    }
    else if (mini_pos == INT_MAX)
    {
        cout << -max_neg << endl;
    }
    else if (max_neg == INT_MIN)
    {
        cout << mini_pos << endl;
    }
    else
    {
        cout << min(mini_pos, -max_neg) << endl;
    }

    return 0;
}
