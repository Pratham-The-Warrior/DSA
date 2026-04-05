#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull basis[62];
int sz = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        ull val;
        cin >> type >> val;

        if (type == 1)
        {
            for (int i = 60; i >= 0; i--)
            {
                if (!(val & (1ULL << i)))
                    continue;

                if (!basis[i])
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (val & (1ULL << j))
                            val ^= basis[j];
                    }
                    for (int j = 60; j > i; j--)
                    {
                        if (basis[j] & (1ULL << i))
                            basis[j] ^= val;
                    }
                    basis[i] = val;
                    sz++;
                    break;
                }
                val ^= basis[i];
            }
        }
        else
        {

            if (sz < 60 && val > (1ULL << sz))
            {
                cout << -1 << endl;
            }
            else
            {
                ull target = val - 1;
                ull result = 0;
                int current_bit = 0;

                for (int i = 0; i <= 60; i++)
                {
                    if (basis[i])
                    {
                        if ((target >> current_bit) & 1)
                        {
                            result ^= basis[i];
                        }
                        current_bit++;
                    }
                }
                cout << result << endl;
            }
        }
    }

    return 0;
}
