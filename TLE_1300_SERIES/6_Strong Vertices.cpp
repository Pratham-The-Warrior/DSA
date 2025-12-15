/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

/****************************BruteForce*************************/
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
//         vector<long long> a(n + 1), b(n + 1), res;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> b[i];
//         }

//         int ans = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int c = 0;
//             for (int j = 1; j <= n; j++)
//             {
//                 if (i == j)
//                     continue;
//                 long long d1 = a[i] - a[j];
//                 long long d2 = b[i] - b[j];
//                 if (d1 >= d2)
//                 {
//                     c++;
//                 }
//             }
//             if (c == n - 1)
//             {
//                 ans++;
//                 res.push_back(i);
//             }
//         }
//         sort(res.begin(), res.end());
//         cout << res.size() << endl;
//         for (auto x : res)
//             cout << x << " ";
//         cout << endl;
//     }

//     return 0;
// }

/***************************OPTIMIZED***************************/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        vector<long long> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];

        long long maxDiff = LLONG_MIN;
        for (int i = 1; i <= n; i++)
            maxDiff = max(maxDiff, a[i] - b[i]);

        vector<int> res;
        for (int i = 1; i <= n; i++)
            if (a[i] - b[i] == maxDiff)
                res.push_back(i);

        cout << res.size() << "\n";
        for (int x : res)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}