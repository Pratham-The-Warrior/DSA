/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

long long countTrailingZeroes(long long n)
{
    long long res = 0;

    while (n % 10 == 0)
    {
        res++;
        n /= 10;
    }
    return res;
}

int countDigits(long long n)
{
    // zero has 1 digit
    if (n == 0)
        return 1;

    int res = 0;

    while (n > 0)
    {
        res++;
        n /= 10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*obs*
    ->in odd cases i think always anna will win as at last sasha wont be able to make a move
    ->4 5000123 3 ->50001234 3 ->
    ->3 4 123 5000 ->
    */

    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<pair<long long, long long>> v;

        for (int i = 0; i < n; i++)
        {
            long long ct1 = countDigits(a[i]);
            long long ct2 = countTrailingZeroes(a[i]);
            v.push_back({ct2, ct1});
        }

        sort(v.rbegin(), v.rend());

        // now sasha will take alternate values from it as i.e 2 4 6 ...
        // and anna as she has first move => 1 3 5 ...

        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 != 0)
            {
                total += v[i].second; // sasha move
            }
            else
            {
                total += v[i].second - v[i].first; // anna move
            }
        }

        if (total > m)
        {
            cout << "Sasha" << endl;
        }
        else
        {
            cout << "Anna" << endl;
        }
    }

    return 0;
}
