/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll x, ll y)
{
    if (x == 0 || y == 0)
        return 0;
    return (x / __gcd(x, y)) * y;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ====================================

    i think for each element we can change it value only if the change we do adds up a prime factor in it
    that doesnt bother gcd with any other element of vector a ,
    so


    8 10 10 12 12 14
    8 10 10 12 12 14  like in this case if we change 8 to 4 it wont chnage the gcd of it with any other element as
    no other element has 4 2s in their prime factor similarly we can make 14 as 2 that also wont change gcd with any other
    elemnt as no other has two 7s

    so answer will be 2

    (lcm can be used to check)
    then iterate over each a[i] indivisual factors check if there is any factor that is unique to it (i.e not in any other elemnts factors)
    if this is true then we can change the value of that a[i] to a[i]/(that factor)  this would make sure the chnage the value of a[i]
    won`t affect the gcd of any subaay
    if this happens ans++ (this is what we want maximum such changes we can achevie)
    check this for each element of vector a
    here b[i] is just the copy of vector a ignore it

     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        if (n < 2)
        {
            cout << 0 << endl;
            continue;
        }

        vector<ll> adj_gcd(n - 1); // simulating prefix gcd
        for (int i = 0; i < n - 1; i++)
        {
            adj_gcd[i] = __gcd(a[i], a[i + 1]);
        }

        int ops = 0;
        for (int i = 0; i < n; i++)
        {
            ll d;
            if (i == 0)
            {
                d = adj_gcd[0];
            }
            else if (i == n - 1)
            {
                d = adj_gcd[n - 2];
            }
            else
            {
                d = lcm(adj_gcd[i - 1], adj_gcd[i]);
            }
            if (d < a[i]) // can be reduced
            {
                ops++;
            }
        }

        cout << ops << endl;
    }

    return 0;
}