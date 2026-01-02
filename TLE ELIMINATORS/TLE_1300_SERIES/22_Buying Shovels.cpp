/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long long i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

long long proper_divisor(long long n)
{
    long long ans = 1;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n)
                ans = max(ans, i);
            long long j = n / i;
            if (j != n)
                ans = max(ans, j);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (k >= n)
        {
            cout << 1 << endl;
        }
        else if (k == 1)
        {
            cout << n << endl;
        }
        else
        {
            if (isPrime(n))
            {
                cout << n << endl;
            }
            else
            {
                long long div = 1;

                for (long long i = 1; i * i <= n; i++)
                {
                    if (n % i == 0)
                    {
                        if (i <= k)
                            div = max(div, i);
                        long long j = n / i;
                        if (j <= k)
                            div = max(div, j);
                    }
                }
                cout << n / div << endl;
            }
        }
    }

    return 0;
}
