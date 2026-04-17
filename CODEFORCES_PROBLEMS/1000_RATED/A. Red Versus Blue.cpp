/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

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
        // Your code here
        int n, r, b;
        cin >> n >> r >> b;

        if (r >= b)
        {
            int slots = b + 1;
            int gap = r / slots;
            int extra = r % slots;

            for (int i = 0; i < slots; i++)
            {
                for (int j = 0; j < gap; j++)
                {
                    cout << "R";
                }
                if (extra > 0)
                {
                    cout << "R";
                    extra--;
                }
                if (i < b)
                    cout << "B";
            }
        }
        else
        {
            int slots = r + 1;
            int gap = b / slots;
            int extra = b % slots;

            for (int i = 0; i < slots; i++)
            {
                for (int j = 0; j < gap; j++)
                {
                    cout << "B";
                }
                if (extra > 0)
                {
                    cout << "B";
                    extra--;
                }
                if (i < r)
                    cout << "R";
            }
        }
        cout << endl;
    }

    return 0;
}