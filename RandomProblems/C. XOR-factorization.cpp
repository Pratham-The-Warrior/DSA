#include <bits/stdc++.h>
using namespace std;

/*
 Goal:
 Construct k non-negative integers a[0..k-1] such that:
 1) a[i] <= n
 2) a[0] ^ a[1] ^ ... ^ a[k-1] = n
*/

void solve()
{
    long long n;
    int k;
    cin >> n >> k;

    vector<long long> a(k, 0);

    // Process bits from highest to lowest
    for (int bit = 30; bit >= 0; bit--)
    {
        long long value = 1LL << bit;
        bool evenCount = true; // true = even number of assignments so far
        int lastIndex = -1;

        // Try to assign this bit greedily
        for (int i = 0; i < k; i++)
        {
            if (a[i] + value <= n)
            {
                a[i] += value;
                evenCount = !evenCount;
                lastIndex = i;
            }
        }

        // If n has this bit set, we need ODD count
        if (n & value)
        {
            if (evenCount && lastIndex != -1)
            {
                a[lastIndex] -= value;
            }
        }
        // If n does NOT have this bit set, we need EVEN count
        else
        {
            if (!evenCount && lastIndex != -1)
            {
                a[lastIndex] -= value;
            }
        }

        // Keep array balanced for future bits
        sort(a.begin(), a.end());
    }

    // Output result
    for (long long x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
