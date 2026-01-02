#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;
static const int MAXN = 200000;

long long fact[MAXN + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute factorials
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();
        vector<int> runs;

        // Build run lengths
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && s[j] == s[i])
                j++;
            runs.push_back(j - i);
            i = j;
        }

        long long deletions = 0;
        long long ways = 1;

        for (int len : runs)
        {
            deletions += (len - 1);
            ways = (ways * len) % MOD;
        }

        ways = (ways * fact[deletions]) % MOD;

        cout << deletions << " " << ways << "\n";
    }

    return 0;
}
