/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

// helper function
ll power(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInv(ll n)
{
    return power(n, MOD - 2);
}

ll nCr(int n, int r, const vector<ll> &fact)
{
    if (r < 0 || r > n)
        return 0;
    ll num = fact[n];
    ll den = (fact[r] * fact[n - r]) % MOD;
    return (num * modInv(den)) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
    total n/3 independedt triangles
    to maximize edge weight while making n/2 = blue nodes and n/2 = red nodes

    one greedy way i am thining is like
    make n/2 triangles with red dominant like 2red and 1blue node
    and make remaining n/2 with blue dominant 2blue and 1 red nodes

    and color 2 dominant such that the connecting node of these two has least edge weight
    this would maximize  sum of weights of edges connecting two vertices with different colors.


    */

    /*
    GOAL
    We have to find number of valid ways to get that max weight
    by various valid colorings
    */
    ll n;
    cin >> n;

    /*each triplet reprseents
    The graph has the following structure: it is split into n3
    triples of vertices, the first triple consisting of vertices 1,2,3
    , the second triple consisting of vertices 4,5,6
    , and so on. Every pair of vertices from the same triple is connected by an edge
    */

    ll ways = 1;

    for (int i = 0; i < n / 3; i++)
    {
        vector<int> w(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> w[j];
        }
        sort(w.begin(), w.end());

        if (w[0] == w[1] && w[1] == w[2])
        {
            ways = (ways * 3) % MOD;
        }
        else if (w[0] == w[1])
        {
            ways = (ways * 2) % MOD;
        }
        else
        {
            ways = (ways * 1) % MOD;
        }
    }

    vector<ll> fact(n / 3 + 1); // precomputation
    fact[0] = 1;
    for (int i = 1; i <= n / 3; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll combinations = nCr(n / 3, n / 6, fact);
    ll ans = (combinations * ways) % MOD;

    cout << ans << endl;

    return 0;
}