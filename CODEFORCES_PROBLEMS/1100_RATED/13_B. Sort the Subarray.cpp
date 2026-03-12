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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        int l = 0, r = n - 1;

        // Find the first position where a and b differ from the left
        while (l < n && a[l] == b[l])
        {
            l++;
        }

        // Find the first position where a and b differ from the right
        while (r >= 0 && a[r] == b[r])
        {
            r--;
        }

        // Expand left if possible (non-decreasing in b)
        while (l > 0 && b[l - 1] <= b[l])
        {
            l--;
        }

        // Expand right if possible (non-decreasing in b)
        while (r < n - 1 && b[r] <= b[r + 1])
        {
            r++;
        }

        // Output 1-based indices
        cout << (l + 1) << " " << (r + 1) << endl;
    }

    return 0;
}