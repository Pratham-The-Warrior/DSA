#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        long long r = round(sqrt(n));
        if (r * r != n)
        {
            cout << "No" << endl;
            continue;
        }

        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            int row = i / r;
            int col = i % r;

            if (row == 0 || row == r - 1 || col == 0 || col == r - 1)
            {
                if (s[i] != '1')
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if (s[i] != '0')
                {
                    ok = false;
                    break;
                }
            }
        }

        if (ok)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}