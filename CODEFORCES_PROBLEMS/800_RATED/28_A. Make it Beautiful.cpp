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

        if (count(a.begin(), a.end(), a[0]) == n)
        {
            cout << "NO\n";
            continue;
        }

        sort(a.begin(), a.end());

        vector<int> ans;
        int l = 0, r = n - 1;

        while (l <= r)
        {
            if (l <= r)
                ans.push_back(a[r--]);
            if (l <= r)
                ans.push_back(a[l++]);
        }

        cout << "YES" << endl;
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
