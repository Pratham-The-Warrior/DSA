/* ************************************************
 * *
 * P    R    A    T    H    A    M    *
 * *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check(vector<vector<int>> &v, int l, int h)
{
    int ct1 = 0, ct2 = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[h][i] != v[l][n - i - 1])
        {
            ct1++;
        }
    }

    return ct1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // i will have to count minimum operation to make
    // ith row from top be mirror image of n-i-1th row
    // if count <= k cout YES else NO

    // to get minimum to convert to mirror image one time we will check if i convert ith to n-i-1th mirro or vice cersa whichver gives less will
    // be considered do this for all pairs

    int t;
    cin >> t;
    while (t--)
    {

        ll n, k;
        cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }

        ll count = 0;
        bool ok = true;

        for (int i = 0; i < n / 2; i++)
        {
            count += check(v, i, n - i - 1);
        }

        //  Handle the middle row for odd-sized matrices
        if (n % 2 != 0)
        {
            count += check(v, n / 2, n / 2) / 2;
        }

        int remaining = k - count;
        if (remaining < 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}