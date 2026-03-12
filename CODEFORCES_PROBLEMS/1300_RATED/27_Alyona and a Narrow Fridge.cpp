/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long> &a, long long mid, long long h)
{
    vector<long long> temp(a.begin(), a.begin() + mid);
    sort(temp.rbegin(), temp.rend());
    // i will take sum of largest num alternatively as pairwise height is needed
    long long res = 0;
    for (int i = 0; i < mid; i += 2)
    {
        res += temp[i];
    }

    return res <= h;
}

int main()
{

    long long n, h;
    cin >> n >> h;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    /*******binary search*****/
    // long long int l = 0, r = n, mid = 0, ans = 1;

    // while (l <= r)
    // {
    //     mid = (l + r) / 2;

    //     if (check(a, mid, h))
    //     {
    //         l = mid + 1;
    //         ans = max(ans, mid);
    //     }
    //     else
    //     {
    //         r = mid - 1;
    //     }
    // }

    /**********brute forec*******/
    long long ans = 1;

    for (int i = n; i >= 1; i--)
    {
        if (check(a, i, h))
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}