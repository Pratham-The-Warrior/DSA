/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void modify(vector<long long> &a, int x)
{
    long long val = 1LL << x;
    long long add = 1LL << (x - 1);

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % val == 0)
        {
            a[i] += add;
        }
    }
}

int main()
{
    // fast i/o needed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int min_x = 31;
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;

            // Only modify if x is smaller than any x processed so far
            if (x < min_x)
            {
                modify(a, x);
                min_x = x;
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}