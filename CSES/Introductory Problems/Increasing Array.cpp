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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll cost = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            cost += (a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }

    cout << cost << endl;

    return 0;
}