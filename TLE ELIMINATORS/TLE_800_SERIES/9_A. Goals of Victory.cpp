/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        vector<int> a(n - 1);
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        cout << -sum << endl;
    }

    return 0;
}