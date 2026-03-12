/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;

    long long weeks = n - k + 1;

    long long window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += a[i];
    }

    long long total = window_sum;

    for (int i = 1; i < weeks; i++) // weeks-1 times loops will run
    {
        window_sum += a[i + k - 1] - a[i - 1]; // adding new added - last removed
        total += window_sum;
    }

    double ans = (double)total / weeks;
    cout << fixed << setprecision(6) << ans;
}
