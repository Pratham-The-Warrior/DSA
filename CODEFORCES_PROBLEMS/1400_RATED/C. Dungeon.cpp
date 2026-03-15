/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * Finds the smallest sword damage that is >= monster health.
 * Time Complexity: O(log N)
 */
auto find_best_sword(ll monster_hp, multiset<ll> &swords)
{
    return swords.lower_bound(monster_hp);
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    multiset<ll> swords;
    for (int i = 0; i < n; i++)
    {
        ll val;
        cin >> val;
        swords.insert(val);
    }

    vector<ll> b(m), c(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];

    // Stage separation: {health, reward}
    // Kill reward-giving monsters first to upgrade swords.
    vector<pair<ll, ll>> stage1, stage2;
    for (int i = 0; i < m; i++)
    {
        if (c[i] > 0)
        {
            stage1.push_back({b[i], c[i]});
        }
        else
        {
            stage2.push_back({b[i], 0});
        }
    }
    sort(stage1.begin(), stage1.end());
    sort(stage2.begin(), stage2.end());

    int ans = 0;

    // --- STAGE 1 ---
    // Use the smallest sufficient sword to maximize the reward upgrade.
    for (auto &monster : stage1)
    {
        auto it = find_best_sword(monster.first, swords);
        if (it != swords.end())
        {
            ans++;
            ll sword_dmg = *it;
            swords.erase(it);
            swords.insert(max(sword_dmg, monster.second));
        }
    }

    // --- STAGE 2 ---
    // Use remaining swords on non-reward monsters; swords disappear forever here.
    for (auto &monster : stage2)
    {
        auto it = find_best_sword(monster.first, swords);
        if (it != swords.end())
        {
            ans++;
            swords.erase(it);
        }
    }

    cout << ans << "\n";
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}