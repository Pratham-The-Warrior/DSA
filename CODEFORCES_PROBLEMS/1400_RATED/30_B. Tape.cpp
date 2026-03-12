/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (k >= m)
    {
        cout << 1 << endl;
        return;
    }

    ll parts_remove = 0;

    vector<ll> diff;

    for (int i = 0; i < n - 1; i++)
    {
        diff.push_back(a[i + 1] - a[i] - 1);
    }

    sort(diff.begin(), diff.end());

    for (int i = 0; i < n - k; i++)
    {
        parts_remove += diff[i];
    }

    cout << n + parts_remove << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}