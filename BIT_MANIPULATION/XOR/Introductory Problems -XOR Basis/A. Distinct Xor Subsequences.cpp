#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 1100  (x)
^1011  (basis[3])
-------
 0111  (New x)

 cleaning the bits
 also you can see all the set bits are still conserved

 we ware basically making sure set bits dont repeat


*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> basis(62, 0);
    int basis_size = 0;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        for (int j = 60; j >= 0; j--)
        {
            if (!(x & (1LL << j)))
                continue;

            if (!basis[j])
            {
                basis[j] = x;
                basis_size++;
                break;
            }

            x ^= basis[j];
        }
    }
    cout << (1ULL << basis_size) << endl;

    return 0;
}
