#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int binexpo(int a, int p)
{
    int res = 1;
    a %= MOD;
    while (p)
    {
        if (p & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        p >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    pair<int, int> max_a = {-1, -1}, max_b = {-1, -1};

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= max_a.first)
            max_a = {a[i], i};
        if (b[i] >= max_b.first)
            max_b = {b[i], i};

        int idx1_A = max_a.second;
        int idx1_B = i - max_a.second;

        // Logic block 2: Using max of B
        int idx2_A = i - max_b.second;
        int idx2_B = max_b.second;

        if (max_a.first > max_b.first)
        {
            cout << (binexpo(2, a[idx1_A]) + binexpo(2, b[idx1_B])) % MOD << " ";
        }
        else if (max_b.first > max_a.first)
        {
            cout << (binexpo(2, a[idx2_A]) + binexpo(2, b[idx2_B])) % MOD << " ";
        }
        else
        {
            if (a[idx1_A] + b[idx1_B] >= a[idx2_A] + b[idx2_B])
            {
                cout << (binexpo(2, a[idx1_A]) + binexpo(2, b[idx1_B])) % MOD << " ";
            }
            else
            {
                cout << (binexpo(2, a[idx2_A]) + binexpo(2, b[idx2_B])) % MOD << " ";
            }
        }
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}