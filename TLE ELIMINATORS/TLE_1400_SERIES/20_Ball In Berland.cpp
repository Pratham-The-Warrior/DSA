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
    total pairs possible n*(n-1)/2
    i will subtract pirs with same a[i] first
    then i will subtract pairs with same b[i]
    then i will add pais which are counted twice in i.e which have same a[i] and b[i]
    */

    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(k), b(k);
        map<ll, ll> mp1, mp2;
        set<pair<ll, ll>> st;
        for (ll i = 0; i < k; i++)
        {
            cin >> a[i];
            mp1[a[i]]++;
        }
        for (ll i = 0; i < k; i++)
        {
            cin >> b[i];
            mp2[b[i]]++;
        }

        for (ll i = 0; i < k; i++)
        {
            st.insert({a[i], b[i]});
        }

        ll ans = k * (k - 1) / 2;

        for (auto x : mp1)
        {
            ans -= x.second * (x.second - 1) / 2;
        }
        for (auto x : mp2)
        {
            ans -= x.second * (x.second - 1) / 2;
        }

        ans += (k - st.size());

        cout << ans << endl;
    }

    return 0;
}
