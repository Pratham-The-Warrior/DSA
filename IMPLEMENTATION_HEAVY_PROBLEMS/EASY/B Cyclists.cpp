#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, p, m;
        cin >> n >> k >> p >> m;

        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        int ans = 0;
        vector<int> temp = a;

        int pos = p - 1; // current position of win card

        while (true)
        {
            int choose = -1;

            // If win card is in first k, we can play it
            if (pos < k)
            {
                choose = pos;
            }
            else
            {
                // choose the smallest among first k (excluding win card)
                int best = INT_MAX;
                for (int i = 0; i < k; i++)
                {
                    if (i == pos)
                        continue;
                    if (temp[i] < best)
                    {
                        best = temp[i];
                        choose = i;
                    }
                }
            }

            if (m < temp[choose])
                break;

            m -= temp[choose];

            int card = temp[choose];
            temp.erase(temp.begin() + choose);
            temp.push_back(card);

            if (choose < pos)
                pos--;
            else if (choose == pos)
            {
                ans++;
                pos = temp.size() - 1;
            }
        }

        cout << ans << endl;
    }
}
