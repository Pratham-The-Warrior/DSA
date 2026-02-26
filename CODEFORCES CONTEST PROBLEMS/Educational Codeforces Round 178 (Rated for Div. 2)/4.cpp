#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Logic:
   - "Beautiful" means sum(new_array) <= sum(original_subset).
   - "Ideal" requires pairwise GCD = 1 and elements >= 2.
   - The cheapest way to satisfy "Ideal" for k elements is the first k primes.
   - We sort 'a' descending to maximize our "budget" for any k.
*/

const int MAX_K = 400005;
const int SIEVE_LIMIT = 6000000;
vector<ll> pref_p;

void precompute_primes()
{
    vector<bool> is_prime(SIEVE_LIMIT, true);
    is_prime[0] = is_prime[1] = false;

    pref_p.push_back(0);
    int count = 0;
    for (int p = 2; p < SIEVE_LIMIT && count < MAX_K; p++)
    {
        if (is_prime[p])
        {
            pref_p.push_back(pref_p.back() + p);
            count++;
            if (1LL * p * p < SIEVE_LIMIT)
            {
                for (int i = p * p; i < SIEVE_LIMIT; i += p)
                    is_prime[i] = false;
            }
        }
    }
}

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    int maxi = 0;
    ll current_a_sum = 0;

    for (int k = 1; k <= n; k++)
    {
        current_a_sum += a[k - 1];

        if (k < pref_p.size() && current_a_sum >= pref_p[k])
        {
            maxi = k;
        }
        else
        {

            break;
        }
    }

    cout << n - maxi << "\n";
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_primes();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}