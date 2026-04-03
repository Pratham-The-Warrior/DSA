#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        b = a;

        int ct2 = 0;
        bool ok = false;

        for (int i = 0; i < n; i++)
        {
            while (b[i] % 2 == 0)
            {
                ct2++;
                b[i] /= 2;
            }
            if (ct2 >= 2)
            {
                ok = true;
                break;
            }
        }

        // case k==4
        if (k == 4)
        {

            int mod = 1e9;
            for (int i = 0; i < n; i++)
            {
                mod = min(mod, (4 - (a[i] % 4)) % 4);
            }

            if (ok)
                cout << 0 << endl;
            else if (ct2 == 1)
                cout << 1 << endl;
            else
                cout << min(2, mod) << endl;
            continue;
        }

        // Case k == 2
        if (k == 2)
        {
            if (ct2 >= 1)
                cout << 0 << endl;
            else
                cout << 1 << endl;
            continue;
        }

        // Case k == 3
        if (k == 3)
        {
            int mod = 1e9;
            for (int i = 0; i < n; i++)
            {
                mod = min(mod, (3 - (a[i] % 3)) % 3);
            }
            cout << mod << endl;
            continue;
        }

        // Case k == 5
        int mod = 1e9;
        for (int i = 0; i < n; i++)
        {
            mod = min(mod, (5 - (a[i] % 5)) % 5);
        }
        cout << mod << endl;
    }

    return 0;
}