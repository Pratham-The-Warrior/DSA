#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> nextDiff(n, n);

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] != a[i + 1])
                nextDiff[i] = i + 1;
            else
                nextDiff[i] = nextDiff[i + 1];
        }

        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--; // convert to 0-based indexing

            if (nextDiff[l] <= r)
                cout << l + 1 << " " << nextDiff[l] + 1 << "\n";
            else
                cout << "-1 -1\n";
        }
    }

    return 0;
}
