/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M      *
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

        int ans = -1;
        for (int i = 0; i <= 1023; i++) // skip i = 0
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                temp ^= (a[j] ^ i);
            }

            if (temp == 0)
            {
                ans = i;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
