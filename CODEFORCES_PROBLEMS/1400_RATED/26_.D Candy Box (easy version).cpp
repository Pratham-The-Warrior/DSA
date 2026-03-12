#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        unordered_map<int, int> freq;
        for (int x : a)
            freq[x]++;

        vector<int> counts;
        for (auto &p : freq)
            counts.push_back(p.second);

        sort(counts.rbegin(), counts.rend());

        int prev = INT_MAX;
        long long ans = 0;

        for (int f : counts)
        {
            int take = min(f, prev - 1);
            if (take <= 0)
                break;
            ans += take;
            prev = take;
        }

        cout << ans << "\n";
    }

    return 0;
}
