/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

double myPow(double x, long long int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return myPow(1 / x, -n);
    double half = myPow(x, n / 2);

    if (n & 1)
        return half * half * x;
    return half * half;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        double x;
        long long n;
        cin >> x >> n;

        cout << myPow(x, n) << endl;
    }

    return 0;
}