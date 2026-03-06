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

        int first, last, x;
        cin >> first;
        last = first;

        int groups = 1;

        for (int i = 1; i < n; i++)
        {
            cin >> x;

            if (x > first && x <= last + 1)
            {
                last = x;
            }
            else
            {
                groups++;
                first = last = x;
            }
        }

        cout << groups << endl;
    }

    return 0;
}