/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long lcm_of_first_k(int k)
{
    long long lcm = 1;
    for (int i = 1; i <= k; i++)
    {
        lcm = (lcm * i) / __gcd(lcm, (long long)i);
    }
    return lcm;
}

int max_interval_size(long long n)
{
    int low = 1, high = 60;
    int result = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long lcm = lcm_of_first_k(mid);

        if (n % lcm == 0)
        {
            result = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << max_interval_size(n) << endl;
    }
    return 0;
}
