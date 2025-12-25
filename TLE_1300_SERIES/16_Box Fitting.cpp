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
        long long W;
        cin >> n >> W;

        vector<long long> cnt(61, 0);

        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            cnt[__builtin_ctzll(x)]++; // set bit calculator
        }

        long long height = 0;

        while (true)
        {
            long long remaining = W;
            bool placed = false;

            for (int bit = 60; bit >= 0; bit--)
            {
                if (cnt[bit] == 0)
                    continue;

                long long width = 1LL << bit;
                long long canPlace = min(cnt[bit], remaining / width);

                if (canPlace > 0)
                {
                    cnt[bit] -= canPlace;
                    remaining -= canPlace * width;
                    placed = true;
                }
            }

            if (!placed)
                break;

            height++;
        }

        cout << height << '\n';
    }

    return 0;
}
