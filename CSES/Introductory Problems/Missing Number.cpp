/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    for (auto x : a)
    {
        sum += x;
    }

    ll total = n * (n + 1) / 2;

    cout << total - sum;

    return 0;
}