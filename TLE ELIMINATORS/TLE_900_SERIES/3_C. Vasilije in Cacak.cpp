/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M      *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> k >> x;

        ll min_possible = k * (k + 1) / 2;
        ll max_possible = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

        cout << ((min_possible <= x && x <= max_possible) ? "YES" : "NO") << endl;
    }

    return 0;
}
