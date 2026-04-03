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

    /* ====================================
     basically for each person i have to check
     if i can find a element greater than him >= (lower_bound) also also ensure that it is  <= a[i]+k
     ====================================*/

    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    multiset<ll> b; // always sorted , O(logn) access time

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        b.insert(x);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = b.lower_bound(a[i] - k);

        if (it != b.end() && *it <= a[i] + k)
        {
            count++;
            b.erase(it);
        }
    }

    cout << count;

    return 0;
}