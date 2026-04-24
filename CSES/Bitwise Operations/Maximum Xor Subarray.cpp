/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
we want max(subarray XOR)
    subarray(l,r)=prefix[r]⊕prefix[l]
        =>Find two prefix values whose XOR is maximum


*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    we want the maimum value of pref[i]^prefix[j]
    Instead of checking all pairs, we build the answer bit by bit from the most significant bit (MSB) to the least.
    */

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] ^ a[i];
    }

    int ans = 0, mask = 0;

    for (int bit = 31; bit >= 0; bit--)
    {
        mask |= (1 << bit);
        // mask keeps all bits from MSB down to this bit
        unordered_set<int> s;
        for (auto p : prefix)
        {
            s.insert(p & mask);
        }

        int num = ans | (1 << bit); // bit set

        for (auto p : prefix)
        {
            if (s.count((p & mask) ^ num))
            {
                ans = num;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
