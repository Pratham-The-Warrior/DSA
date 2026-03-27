#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
}

/*

*****IF NO CONDITION ON MOVEMENT*******
You can move freely on infinite grid,
count sequences reaching final position
***************************************

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 200005;

ll fact[MAXN], invfact[MAXN];

ll modexp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;

    invfact[MAXN-1] = modexp(fact[MAXN-1], MOD-2);
    for (int i = MAXN-2; i >= 0; i--)
        invfact[i] = invfact[i+1] * (i+1) % MOD;
}

ll multinomial(int x, int y, int z, int w) {
    ll res = fact[x+y+z+w];
    res = res * invfact[x] % MOD;
    res = res * invfact[y] % MOD;
    res = res * invfact[z] % MOD;
    res = res * invfact[w] % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    string s;
    cin >> s;

    int c = count(s.begin(), s.end(), '?');
    int c1 = count(s.begin(), s.end(), 'U');
    int c2 = count(s.begin(), s.end(), 'D');
    int c3 = count(s.begin(), s.end(), 'R');
    int c4 = count(s.begin(), s.end(), 'L');

    int A = c1 + 6 - c2;
    int B = c4 - c3;

    if ((c - A - B) % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }

    int S = (c - A - B) / 2;

    ll ans = 0;

    for (int y = 0; y <= S; y++) {
        int w = S - y;

        int x = y + A;
        int z = w + B;

        if (x < 0 || z < 0) continue;

        ans = (ans + multinomial(x, y, z, w)) % MOD;
    }

    cout << ans << "\n";
}
*/