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

    int t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<ll> cost(n);

        for (int i = 0; i < n; i++)
        {
            cost[i] = i + 1 + a[i];
        }

        sort(cost.begin(), cost.end());

        int ct = 0;
        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += cost[i];
            if (sum > c)
            {
                break;
            }
            ct++;
        }

        cout << ct << endl;
    }

    return 0;
}