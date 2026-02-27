/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> primes;

// Precompute primes up to 50000
void precompute_primes()
{
    const int LIMIT = 50000;
    vector<bool> isPrime(LIMIT, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < LIMIT; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < LIMIT; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i < LIMIT; i++)
        if (isPrime[i])
            primes.push_back(i);
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
        ll n;
        cin >> n;

        ll ans = 1;
        ll temp = n;

        for (int p : primes)
        {
            if ((ll)p * p > temp)
                break;

            if (temp % p == 0)
            {
                ans *= p;
                while (temp % p == 0)
                    temp /= p; // this will remove all occurences of
            }
        }

        if (temp > 1)
            ans *= temp;

        cout << ans << endl;
    }

    return 0;
}