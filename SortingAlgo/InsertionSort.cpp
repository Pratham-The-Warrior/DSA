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

        // Insertion Sort
        for (int i = 1; i < n; i++)
        {
            int key = a[i];
            int j = i - 1;

            // Shift elements greater than key to one position ahead
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }

        for (auto x : a)
        {
            cout << x << " ";
        }
        cout << "\n"; // better formatting for multiple test cases
    }

    return 0;
}
