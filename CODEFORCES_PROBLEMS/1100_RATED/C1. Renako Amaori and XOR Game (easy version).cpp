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

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int total_xor = 0;
        for (int i = 0; i < n; i++)
        {
            total_xor ^= (a[i] ^ b[i]);
        }

        if (total_xor == 0)
        {
            cout << "Tie" << endl;
            continue;
        }

        int msb = 31 - __builtin_clz(total_xor);

        int last_idx = -1;
        int current_a_msb = 0;

        for (int i = 0; i < n; i++)
        {
            // Track the 'default' state of the MSB in array A
            if ((a[i] >> msb) & 1)
                current_a_msb ^= 1;

            // If this index allows a swap that affects the MSB
            if (((a[i] ^ b[i]) >> msb) & 1)
            {
                last_idx = i;
            }
            // if(a[i]!=b[i]){
            //     last_idx=i;
            // }
        }

        // 3. Logic: The last person who can touch the MSB decides its fate.
        // If Ajisai (even index) is last, she wins. If Mai (odd index) is last, she wins.
        // BUT: If the initial bit is already 1 and NO ONE can flip it, Ajisai wins.

        cout << (last_idx % 2 == 0 ? "Ajisai" : "Mai") << endl;
    }

    return 0;
}