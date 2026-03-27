#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> freqMap;
    int maxFreq = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        maxFreq = max(maxFreq, ++freqMap[x]);
    }

    vector<int> freq;
    long long total = 1;
    for (auto &p : freqMap)
    {
        freq.push_back(p.second);
        total = (total * (p.second + 1)) % MOD;
    }

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int c : freq)
    {
        for (int j = n; j >= c; --j)
        {
            dp[j] = (dp[j] + dp[j - c] * c) % MOD;
        }
    }

    long long bad = 0;
    for (int j = 1; j < maxFreq; j++)
    {
        bad = (bad + dp[j]) % MOD;
    }

    long long ans = (total - 1 - bad + MOD) % MOD;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}