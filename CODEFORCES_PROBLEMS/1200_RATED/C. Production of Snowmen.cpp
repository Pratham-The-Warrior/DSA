/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool good(const vector<int> &x, const vector<int> &y, int n, int k)
{
    for (int i = 0; i < n; ++i)
    {
        if (x[i] <= y[(i + k) % n])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ====================================

    we need to find the number of triples $(i, j, k)$ such that for all $m \in \{0, \dots, n-1\}$,
    the snowman formed by snowballs at indices $(i+m, j+m, k+m)$ is stable.
    A snowman is stable if its snowball sizes $(a, b, c)$ satisfy $a < b < c$.


     ====================================*/

    /**
     * Checks if every element in array x is strictly greater than
     * the element in array y at the shifted index (i + k) % n.
     */

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];

        long long k1 = 0, k2 = 0;

        for (int i = 0; i < n; ++i)
        {
            if (good(b, a, n, i))
            {
                k1++;
            }
            if (good(c, b, n, i))
            {
                k2++;
            }
        }
        cout << k1 * k2 * 1LL * n << endl;
    }

    return 0;
}