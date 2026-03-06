#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// vector<ll> get_factors(ll num)
// {
//     vector<ll> factors;
//     for (ll i = 1; i * i <= num; i++)
//     {
//         if (num % i == 0)
//         {
//             factors.push_back(i);
//             if (i != num / i)
//                 factors.push_back(num / i);
//         }
//     }
//     return factors;
// }

// bool can_split(const vector<ll> &a, ll x)
// {
//     ll current_sum = 0;
//     ll segments = 0;
//     for (ll val : a)
//     {
//         current_sum += val;
//         if (current_sum % x == 0)
//         {
//             segments++;
//             current_sum = 0;
//         }
//     }
//     return segments >= 2;
// }

// bool isPrime(ll x)
// {
//     if (x <= 1)
//         return false;
//     if (x == 2 || x == 3)
//         return true;
//     if (x % 2 == 0 || x % 3 == 0)
//         return false;
//     for (ll i = 5; i * i <= x; i += 6)
//     {
//         if (x % i == 0 || x % (i + 2) == 0)
//             return false;
//     }
//     return true;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        ll pref = 0;

        ll ans = 1, temp = 1;

        for (int i = 0; i < n - 1; i++)
        {
            pref += a[i];
            ans = max(ans, __gcd(pref, sum - pref));
        }

        cout << ans << endl;
    }

    return 0;
}