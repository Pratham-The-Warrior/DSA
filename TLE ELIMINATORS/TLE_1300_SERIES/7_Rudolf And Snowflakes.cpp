/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long n;
//         cin >> n;

//         bool ok = false;

//         for (long long k = 2; k * k < n && !ok; k++)
//         {
//             long long sum = 1;
//             long long cur = 1;
//             int terms = 1;

//             while (true)
//             {
//                 cur *= k;
//                 sum += cur;
//                 terms++;

//                 if (terms >= 3 && sum == n)
//                 {
//                     ok = true;
//                     break;
//                 }
//                 if (sum > n)
//                     break;
//             }
//         }

//         cout << (ok ? "YES\n" : "NO\n");
//     }
//     return 0;
// }

/*****************OPTIMIZED********************/

#include <bits/stdc++.h>
using namespace std;

bool check(long long n, long long k, int m)
{
    long long sum = 1;
    long long cur = 1;

    for (int i = 1; i <= m; i++)
    {
        if (cur > n / k)
            return false;
        cur *= k;
        if (sum > n - cur)
            return false;
        sum += cur;
    }
    return sum == n;
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

        bool ok = false;

        for (int m = 2; m <= 60 && !ok; m++)
        {
            long long lo = 2, hi = pow(n, 1.0 / m) + 2;

            while (lo <= hi)
            {
                long long mid = (lo + hi) / 2;

                if (check(n, mid, m))
                {
                    ok = true;
                    break;
                }

                // Compare sum(mid) with n indirectly
                long long sum = 1, cur = 1;
                bool overflow = false;
                for (int i = 1; i <= m; i++)
                {
                    if (cur > n / mid)
                    {
                        overflow = true;
                        break;
                    }
                    cur *= mid;
                    if (sum > n - cur)
                    {
                        overflow = true;
                        break;
                    }
                    sum += cur;
                }

                if (overflow || sum > n)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
