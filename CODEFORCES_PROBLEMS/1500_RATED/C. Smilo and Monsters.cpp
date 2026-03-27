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

    /*
    logic :
    See minmum number of +1 ops we need will be sum/2
    hence ans += num/2; min ops needed of +1
    then if sum is odd +1 extra

    now we have to choose least number of elemnents which equal
    of sum/2 bestway to take largest as possible

    so ans = sum%2 + sum/2 + min(to get sum/2)

    */

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());
        ll ans = 0;

        if (sum % 2 != 0)
            ans++;

        ans += (sum / 2); // minimum needed

        sum /= 2;

        ll j = n - 1;

        while (sum > 0)
        {
            sum -= a[j];
            ans++;
            j--;
        }

        cout << ans << endl;
    }

    return 0;
}