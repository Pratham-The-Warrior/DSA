#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        b = a;
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, a[i - 1] - a[i]);
        }

        sort(b.begin(), b.end());

        ans = max({ans, b[n - 1] - a[0], a[n - 1] - b[0]});

        cout << ans << endl;
    }

    return 0;
}