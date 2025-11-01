#include <iostream>
#include <vector>
using namespace std;

vector<long long> primeFactors(long long n)
{
    vector<long long> factors;

    // Step 1: Divide out all factors of 2
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    // Step 2: Check for odd factors
    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    // Step 3: If n is still > 2, then it’s a prime factor
    if (n > 2)
        factors.push_back(n);

    return factors;
}

int main()
{
    long long n;
    // cout << "Enter a number: ";
    cin >> n;

    vector<long long> factors = primeFactors(n);
    // cout << "Prime factors: ";
    for (long long f : factors)
        cout << f << " ";
    cout << endl;

    return 0;
}
