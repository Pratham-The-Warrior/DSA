#include <iostream>
#include <vector>

using namespace std;

long long factorial(int n)
{
    long long res = 1;
    long long mod = 1e9 + 7;
    for (int i = 2; i <= n; i++)
    {
        res = (res * i) % mod;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);

    int all_and;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            all_and = a[i];
        else
            all_and &= a[i];
    }

    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == all_and)
            cnt++;
    }

    if (cnt < 2)
    {
        cout << 0 << endl;
        return;
    }

    long long mod = 1e9 + 7;
    // Result = cnt * (cnt - 1) * (n - 2)!
    long long ans = (cnt * (cnt - 1)) % mod;
    ans = (ans * factorial(n - 2)) % mod;

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}