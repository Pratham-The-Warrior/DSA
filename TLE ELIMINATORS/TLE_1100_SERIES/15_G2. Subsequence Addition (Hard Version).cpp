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

        vector<long long> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        sort(c.begin(), c.end());

        if (c[0] != 1)
        {
            cout << "NO" << endl;
            continue;
        }

        long long sum = 1;
        bool possible = true;

        for (int i = 1; i < n; i++)
        {
            if (c[i] > sum)
            {
                possible = false;
                break;
            }
            sum += c[i];
        }

        cout << (possible ? "YES" : "NO");
        cout << endl;
    }

    return 0;
}