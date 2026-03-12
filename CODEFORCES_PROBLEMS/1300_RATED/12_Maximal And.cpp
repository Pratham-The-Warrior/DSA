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
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long ans = 0;

        // Check bits from 30 till 0
        for (int bit = 30; bit >= 0; bit--)
        {
            long long need = 0;

            // Count how many numbers do not have this bit set
            for (int i = 0; i < n; i++)
            {
                if ((a[i] & (1LL << bit)) == 0)
                {
                    need++;
                }
            }

            if (need <= k)
            {
                k -= need;
                ans |= (1LL << bit);

                // Apply the bit to all elements //
                for (int i = 0; i < n; i++)
                {
                    a[i] |= (1LL << bit);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
