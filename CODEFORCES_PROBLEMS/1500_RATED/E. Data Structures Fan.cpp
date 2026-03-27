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
        /*QUERY ANSWERING PROBLEM*/
        /*INSTRUCTIONS GIVEN JUST NEED TO BE IMPLEMENTED*/
        /*ONLY PROBLEM IS TIME COMPLEXITY*/
        /*TO TACKLE This Precompution will need to be done*/
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] ^ a[i];
        }

        string s;
        cin >> s;
        int x0 = 0, x1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                x0 ^= a[i];
            else
                x1 ^= a[i];
        }
        int q;
        cin >> q;
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int l, r;
                cin >> l >> r;
                // Range XOR sum of a[l-1...r-1]
                int range_xor = pref[r] ^ pref[l - 1];

                // Flipping the range swaps the contributions
                // x0 becomes (x0 ^ range_xor) and x1 becomes (x1 ^ range_xor)
                x0 ^= range_xor;
                x1 ^= range_xor;
                int xor_range = pref[r] ^ pref[l - 1];
            }
            else
            {
                int g;
                cin >> g;
                if (g == 0)
                {
                    cout << x0 << " ";
                }
                else
                {
                    cout << x1 << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}