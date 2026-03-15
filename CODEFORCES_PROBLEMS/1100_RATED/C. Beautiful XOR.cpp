#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int get_msb(ll n)
{
    if (n == 0)
        return -1;
    int msb = 0;
    while (n >>= 1)
        msb++;
    return msb;
}

void solve()
{
    ll a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    // If a ^ b is already <= a, we only need 1 step
    if ((a ^ b) <= a)
    {
        cout << 1 << endl;
        cout << (a ^ b) << endl;
        return;
    }

    int msb_a = get_msb(a);
    int msb_b = get_msb(b);

    // If b has a higher bit set than a's highest bit, it's impossible
    if (msb_b > msb_a)
    {
        cout << -1 << endl;
        return;
    }

    // Otherwise, we can always do it in 2 steps.
    // We create an intermediate value a' by XORing a with (2^msb_a - 1)
    // This ensures a' is large enough to reach b in the next step.
    ll x1 = (1LL << msb_a) - 1;
    ll a_prime = a ^ x1;
    ll x2 = a_prime ^ b;

    cout << 2 << endl;
    cout << x1 << " " << x2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}