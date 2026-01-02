/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        map<int, int> freq;
        vector<vector<int>> groups(n);

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            groups[i].resize(k);

            for (int j = 0; j < k; j++)
            {
                cin >> groups[i][j];
                freq[groups[i][j]]++;
            }
        }

        bool possible = false;

        for (int i = 0; i < n; i++)
        {
            bool valid = true;
            for (int x : groups[i])
            {
                if (freq[x] == 1)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                possible = true;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }

    return 0;
}
