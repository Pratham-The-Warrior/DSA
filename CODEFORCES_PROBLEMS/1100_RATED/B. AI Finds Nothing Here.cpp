#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    // your code goes here

    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, r, c;
        cin >> n >> m >> r >> c;

        // if r*c is even all elmenents can be made 0 overall xor sum can be 0 only or all can be 1
        // and if r*c is odd we need atleast one 1 in every matrix
        // i think (n-r+1)*(m-c+1);
        //

        long long t1 = m * n;

        long long t2 = ((n - r + 1)) * ((m - c + 1));

        long long t3 = (t1 - t2);

        cout << (power(2, t3)) % mod << "\n";
    }
}
