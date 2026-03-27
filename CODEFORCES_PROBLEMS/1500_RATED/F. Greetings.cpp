#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int fenwick[MAXN];

void update(int i)
{
    for (; i < MAXN; i += i & -i)
        fenwick[i]++;
}

int query(int i)
{
    int sum = 0;
    for (; i > 0; i -= i & -i)
        sum += fenwick[i];
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> arr(n);
        vector<int> vals;

        for (auto &p : arr)
        {
            cin >> p.second >> p.first;
            vals.push_back(p.second);
        }

        // coordinate compression
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        for (auto &p : arr)
        {
            p.second = lower_bound(vals.begin(), vals.end(), p.second) - vals.begin() + 1;
        }

        sort(arr.begin(), arr.end());

        memset(fenwick, 0, sizeof(fenwick));

        long long ans = 0;

        for (auto p : arr)
        {
            int x = p.second;

            // elements greater than x = total - <= x
            ans += query(MAXN - 1) - query(x);

            update(x);
        }

        cout << ans << "\n";
    }
}