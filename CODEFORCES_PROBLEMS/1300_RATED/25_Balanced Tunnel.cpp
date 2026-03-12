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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    vector<int> exit_time(n + 1);
    for (int i = 0; i < n; i++)
        exit_time[b[i]] = i;

    int fines = 0;
    int max_exit = 0;

    // this is cute //
    for (int i = 0; i < n; i++)
    {
        int ci = exit_time[a[i]];
        if (ci < max_exit)
            fines++;
        max_exit = max(max_exit, ci);
    }

    cout << fines << endl;
}
