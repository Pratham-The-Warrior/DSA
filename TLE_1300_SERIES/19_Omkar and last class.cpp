/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

/*
given an integer n ,find positive integers a and b such that a+b=n and LCM(a,b)
is the minimum value possible.
*/

long long lcm(long long a, long long b)
{
    return a * b / __gcd(a, b);
}

long long l_g(long long n)
{
    long long ans = 1;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans = max(ans, i);
            if (i != 1)
                ans = max(ans, n / i);
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

        long long n;
        cin >> n;

        if (n % 2 == 0)
        {
            cout << n / 2 << " " << n / 2 << endl;
        }
        else
        {
            long long largest_divisor = l_g(n);

            cout << largest_divisor << " " << n - largest_divisor << endl;
        }
    }

    return 0;
}