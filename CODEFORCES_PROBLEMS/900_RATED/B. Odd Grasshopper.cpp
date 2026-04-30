#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long x, n;
        cin >> x >> n;

        if (n == 0)
        {
            cout << x << endl;
        }
        else
        {
            long long remainder = n % 4;

            if (x % 2 == 0)
            {
                if (remainder == 1)
                    cout << x - n << endl;
                else if (remainder == 2)
                    cout << x + 1 << endl;
                else if (remainder == 3)
                    cout << x + n + 1 << endl;
                else
                    cout << x << endl;
            }
            else
            {
                if (remainder == 1)
                    cout << x + n << endl;
                else if (remainder == 2)
                    cout << x - 1 << endl;
                else if (remainder == 3)
                    cout << x - n - 1 << endl;
                else
                    cout << x << endl;
            }
        }
    }
    return 0;
}