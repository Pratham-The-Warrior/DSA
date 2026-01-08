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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Build Sparse Table for AND
        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;
        vector<vector<long long>> st(LOG, vector<long long>(n));

        for (int i = 0; i < n; i++)
            st[0][i] = a[i];

        for (int j = 1; j < LOG; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[j][i] = st[j - 1][i] & st[j - 1][i + (1 << (j - 1))];
            }
        }

        auto range_and = [&](int L, int R)
        {
            long long result = (1LL << 62) - 1; // all bits 1
            for (int j = LOG - 1; j >= 0; j--)
            {
                if (L + (1 << j) - 1 <= R)
                {
                    result &= st[j][L];
                    L += (1 << j);
                }
            }
            return result;
        };

        long long q;
        cin >> q;
        while (q--)
        {
            long long l, k;
            cin >> l >> k;
            l--; 

            if (a[l] < k)
            { // impossible immediately
                cout << -1 << " ";
                continue;
            }

            int lo = l, hi = n - 1, ans = l;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;
                if (range_and(l, mid) >= k)
                {
                    ans = mid;
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            cout << ans + 1 << " "; 
        }
        cout << "\n";
    }
    return 0;
}
