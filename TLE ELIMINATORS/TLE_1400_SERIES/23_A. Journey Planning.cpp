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
    Let's rewrite the equality given in the statement as ci+1−bci+1=ci−bci
. It means that all cities in our path will have the same value of i−bi
; furthermore, all cities with the same such value can always be visited in ascending order.

So we may group cities by i−bi
, compute the sum in each group and find the maximum over all groups. For example, this can be done by storing the sum for each i−bi
 in an array (be careful with negative values of i−bi
, though!)
    */

    ll n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    map<ll, ll> mp;

    for (int i = 1; i <= n; i++)
    {
        mp[i - a[i]] += a[i];
    }

    ll ans = 0;

    for (auto x : mp)
    {
        ans = max(ans, x.second);
    }

    cout << ans << endl;

    return 0;
}