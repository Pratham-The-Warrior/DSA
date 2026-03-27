/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 If n is even, the algorithm divides it by two, and if n is odd,
 the algorithm multiplies it by three and adds one. The algorithm repeats
 this, until n is one. For example, the sequence for n=3 is as follows:
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    cout << n << " ";
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n *= 3;
            n++;
        }
        cout << n << " ";
    }

    return 0;
}