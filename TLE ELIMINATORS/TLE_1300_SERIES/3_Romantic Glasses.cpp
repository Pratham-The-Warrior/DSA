/************************OPTIMIZED VERSION*********************/

// KIND OF SIMILAR TO LEETCODES MAXIMUM SUBARRAY EQUAL K TYPE PROBLEMS

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
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        set<long long> seen;
        long long prefix = 0;
        bool ok = false;

        seen.insert(0); // Empty prefix

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 2 == 1)
                prefix += a[i];
            else
                prefix -= a[i];

            if (seen.count(prefix))
            {
                ok = true;
                break;
            }
            seen.insert(prefix);
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

/*****************************Brute Force***************************/

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
//         int n;
//         cin >> n;
//         vector<long long> a(n);

//         for (int i = 0; i < n; i++)
//             cin >> a[i];

//         bool ok = false;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 long long odd = 0, even = 0;

//                 for (int k = i; k <= j; k++)
//                 {
//                     if ((k + 1) % 2 == 0)
//                         even += a[k];
//                     else
//                         odd += a[k];
//                 }

//                 if (odd == even)
//                 {
//                     ok = true;
//                     break;
//                 }
//             }
//             if (ok)
//                 break;
//         }

//         cout << (ok ? "YES\n" : "NO\n");
//     }

//     return 0;
// }
