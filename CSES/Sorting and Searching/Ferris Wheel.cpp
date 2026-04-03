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
    each bucket can have 1 or at max 2 childer i.e a[i]
    weight<=x
    minimize cost
    i can simple sort the a[i] then try to stuff as many buckets with 2 childs as possible
    but dont you thinkjust 2 smallest may leave cases like small + big whle that small could be taken with somehwat bigger num??

    again i think we would need to be greedy in choice
    like let x+y be our two childeren that we want to stuff
    y <= k-x so simply find upper bound and check id it-- exists => if it erase that &it from set
    continue till set is not empty
     ====================================*/

    ll n, k;
    cin >> n >> k;

    multiset<ll> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }

    int count = 0;

    while (!s.empty())
    {
        auto it1 = s.begin();
        ll x = *it1;
        s.erase(it1);

        // find best partner <= k - x
        auto it2 = s.upper_bound(k - x);

        if (it2 != s.begin())
        {
            it2--; // largest element <= k - x
            s.erase(it2);
        }

        count++;
    }

    cout << count;
}