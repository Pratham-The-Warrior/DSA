/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M     *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
     =========================================
     Condition:
     max rounds >= required rounds

     min(p / 2, q / 3) >= (q - p)
     =========================================
    */

    int t;
    cin >> t;

    while (t--)
    {
        ll p, q;
        cin >> p >> q;

        // If p >= q, Alice wins immediately
        if (p >= q)
        {
            cout << "Alice\n";
            continue;
        }

        ll diff = q - p; // required rounds
        ll maxP = p / 2; // rounds limited by p
        ll maxQ = q / 3; // rounds limited by q

        // Check if Bob can maintain the invariant
        if (min(maxP, maxQ) >= diff)
        {
            cout << "Bob";
        }
        else
        {
            cout << "Alice";
        }
        cout << endl;
    }

    return 0;
}