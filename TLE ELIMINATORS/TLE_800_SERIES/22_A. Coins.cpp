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
        long long n, k;
        cin >> n >> k;

        if (n % 2 != 0 && k % 2 == 0 || (n < 2 && k > 1))
        {
            cout << "NO";
        }
        else
        {
            cout << "YES";
        }
        cout << endl;
    }

    return 0;
}