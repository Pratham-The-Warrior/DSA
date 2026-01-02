#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<long long>> v, long long k)
{
    long long L = 0, R = 0;

    for (int i = 0; i < v.size(); i++)
    {
        long long nl = v[i][0];
        long long nr = v[i][1];

        long long newL = max(nl, L - k);
        long long newR = min(nr, R + k);

        if (newL > newR)
            return false;
        L = newL;
        R = newR;
    }
    return true;
}

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
        vector<vector<long long>> v(n, vector<long long>(2));
        for (int i = 0; i < n; i++)
            cin >> v[i][0] >> v[i][1];

        long long l = 0, h = 1e9, mid;
        while (l <= h)
        {
            mid = (l + h) / 2;
            if (check(v, mid))
                h = mid - 1; // shrink
            else
                l = mid + 1; // increase
        }
        cout << l << "\n"; // minimal k
    }
}
