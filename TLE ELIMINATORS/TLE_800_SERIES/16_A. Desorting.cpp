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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> b = a;
        sort(b.begin(), b.end());

        if (a != b)
        {
            cout << 0 << endl;
            continue;
        }

        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, a[i + 1] - a[i]);
        }

        cout << ans / 2 + 1 << endl;
    }

    return 0;
}
