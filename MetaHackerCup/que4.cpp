/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// extra functions import needed
// this was tough

ll mpow(ll a, ll b, ll m)
{
    ll r = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

map<ll, int> fct(ll n)
{
    map<ll, int> m;
    for (ll i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            m[i]++;
            n /= i;
        }
    }
    if (n > 1)
        m[n]++;
    return m;
}

ll cmb(ll N, int e)
{
    ll r = 1;
    for (int i = 1; i <= e; ++i)
    {
        r = r * ((N - 1 + i) % MOD) % MOD;
        r = r * mpow(i, MOD - 2, MOD) % MOD;
    }
    return r;
}

void gen_div(const vector<pair<ll, int>> &pr, int idx, ll cur, vector<ll> &div)
{
    if (idx == pr.size())
    {
        div.push_back(cur);
        return;
    }
    ll v = 1;
    for (int i = 0; i <= pr[idx].second; i++)
    {
        gen_div(pr, idx + 1, cur * v, div);
        v *= pr[idx].first;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        auto m = fct(b);

        // i will need to genrated divsiors but n is big  i think i will need to check other way
        vector<pair<ll, int>> pair(m.begin(), m.end());
        vector<ll> div;
        gen_div(pair, 0, 1, div);
        ll ans = 0;
        for (ll d : div)
        {
            if (d > a)
                continue;
            ll w = 1;
            for (auto &p : pair)
            {
                int e = 0;
                ll tmp = d;
                while (tmp % p.first == 0)
                {
                    e++;
                    tmp /= p.first;
                }
                int f = p.second - e;
                w = w * cmb(n, e) % MOD;
                w = w * cmb(n, f) % MOD;
            }
            ans = (ans + w) % MOD;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
