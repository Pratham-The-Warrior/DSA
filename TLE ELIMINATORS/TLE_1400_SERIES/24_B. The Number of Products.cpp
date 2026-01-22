#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll even = 1; // empty prefix
    ll odd = 0;
    ll negCount = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            negCount++;

        if (negCount % 2 == 1)
        {
            ans += even; // agar odd hua toh pair with all even
            odd++;
        }
        else
        {
            ans += odd; // even then all odd ke sath pair
            even++;
        }
    }

    cout << ans << " " << n * (n + 1) / 2 - ans << endl;
    return 0;
}
