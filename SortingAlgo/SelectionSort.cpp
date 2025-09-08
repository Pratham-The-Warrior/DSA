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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[minIdx] > a[j])
                {
                    minIdx = j;
                }
            }

            swap(a[i], a[minIdx]);
        }

        for (auto i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}