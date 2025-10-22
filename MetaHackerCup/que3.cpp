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

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> ans(2 * n, 1); // i will initailize all before the b 1 so my first
        // condition get satisfied then multiply exaclt ly b n ,

        ans[2 * n - 1] = b;

        cout << "Case #" << t << ": ";
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
