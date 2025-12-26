/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

/*
Find 3 distinct integers a, b, c >= 2 such that a * b * c = n
*/

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

vector<long long> factors(long long n)
{
    vector<long long> res;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        if (isPrime(n))
        {
            cout << "NO\n";
            continue;
        }

        vector<long long> f = factors(n);
        if (f.size() < 2)
        {
            cout << "NO\n";
            continue;
        }

        bool ok = false;
        long long a, b, c;

        for (int i = 0; i < (int)f.size() && !ok; i++)
        {
            for (int j = i + 1; j < (int)f.size() && !ok; j++)
            {
                a = f[i], b = f[j];
                if (n % (a * b) != 0)
                    continue;

                c = n / (a * b);
                if (c >= 2 && c != a && c != b)
                {
                    ok = true;
                }
            }
        }

        if (!ok)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
        }
    }
    return 0;
}

/*
Examples:
32 --> NO
12345 --> YES (3 5 823)

32 => 2 2 2 2 2 =>  2 4 8 16
64 =>  2 4 8 16 32

12345 => 3 5 15 823 2469 4115

*/