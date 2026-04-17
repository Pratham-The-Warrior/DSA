/*
*PROBLEM TYPE: Tetration  Power Tower Modulo Computation

We are computing:
    a^(b^c) mod (1e9 + 7)

This involves multiple layers of exponentiation, so direct
computation is impossible due to overflow.

----------------------------------------------------------------------
CORE MATHEMATICAL IDEAS USED
----------------------------------------------------------------------

1. MODULAR ARITHMETIC
---------------------
We work under modulo:
        MOD = 1e9 + 7 (a prime number)

Properties:
    (a * b) % MOD = ((a % MOD) * (b % MOD)) % MOD

This prevents overflow and keeps numbers manageable.

----------------------------------------------------------------------
2. FAST EXPONENTIATION (Binary Exponentiation)
----------------------------------------------
We compute:
        a^b efficiently in O(log b)

Recurrence:
    a^b =
        (a^(b/2))^2         if b is even
        a * (a^(b/2))^2     if b is odd

Time complexity: O(log b)

We always apply modulo at each multiplication step.

----------------------------------------------------------------------
3. CRITICAL IDEA: MODULO OF EXPONENTS
-------------------------------------

We need:
        a^(b^c) mod MOD

Direct computation of b^c is impossible.

So we use:

----------------------------------------------------------------------
4. FERMAT'S LITTLE THEOREM
--------------------------

If MOD is prime (which it is: 1e9+7), then:

    a^(MOD-1) ≡ 1 (mod MOD), for a not divisible by MOD

Therefore exponent reduction rule:

    a^x mod MOD = a^(x mod (MOD-1)) mod MOD

IMPORTANT CONSEQUENCE:
    We can reduce exponent modulo (MOD - 1)

---------------------------------------------------------------------- */
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long a, long long b, long long mod)
{
    long long res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        long long exp = power(b, c, MOD - 1);
        cout << power(a, exp, MOD) << "\n";
    }
}