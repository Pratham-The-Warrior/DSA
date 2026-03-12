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
        int best1 = INT_MAX, best2 = INT_MAX;
        int penalty = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x <= best1)
            {
                best1 = x; // place into first subsequence
            }
            else if (x <= best2)
            {
                best2 = x; // place into second subsequence
            }
            else
            {
                // Cannot place without causing an extra increasing penalty
                penalty++;
                best1 = best2; // replace first ending
                best2 = x;     // start new second chain
            }
        }
        cout << penalty << "\n";
    }

    return 0;
}
