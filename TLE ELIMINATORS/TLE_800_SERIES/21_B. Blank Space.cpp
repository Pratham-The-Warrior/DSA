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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int ans = 0;
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            j = i;
            int temp = 0;
            while (j < n && a[j] == 0)
            {
                j++;
                temp++;
            }
            i = j;
            ans = max(ans, temp);
        }

        cout << ans << endl;
    }

    return 0;
}