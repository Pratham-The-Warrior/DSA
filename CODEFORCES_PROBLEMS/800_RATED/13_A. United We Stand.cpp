#include <bits/stdc++.h>
using namespace std;

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
            cin >> a[i];

        sort(a.begin(), a.end());

        if (a[0] == a[n - 1])
        {
            cout << -1 << "\n";
            continue;
        }

        int mn = a[0];
        int c = count(a.begin(), a.end(), mn);

             cout << c << " " << n - c << "\n";

        for (int i = 0; i < c; i++)
            cout << mn << " ";
        cout << "\n";

        for (int i = c; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}
