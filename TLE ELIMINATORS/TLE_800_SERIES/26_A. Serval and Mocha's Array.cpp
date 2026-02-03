#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, m, a[N];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        m = 1e9;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m = min(m, __gcd(a[i], a[j]));
        cout << (m <= 2 ? "Yes" : "No") << endl;
    }
}