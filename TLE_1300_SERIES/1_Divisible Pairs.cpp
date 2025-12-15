#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long ans = 0;
        map<pair<long long, long long>, long long> mp;

        for (auto k : a)
        {

            long long rx = k % x;
            long long ry = k % y;

            long long needx = (x - rx) % x;
            long long needy = ry;

            ans += mp[{needx, needy}];
            mp[{rx, ry}]++;
        }

        cout << ans << endl;
    }

    return 0;
}

// brute force

// /* ************************************************
//  *                                                *
//  *       P     R     A     T     H     A     M    *
//  *                                                *
//  ************************************************ */
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
//         long long n, x, y;
//         cin >> n >> x >> y;
//         vector<long long> a(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         long long ans = 0;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 long long sum = a[i] + a[j];
//                 long dif = abs(a[i] - a[j]);
//                 if (sum % x == 0 && dif % y == 0)
//                 {
//                     ans++;
//                 }
//             }
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }