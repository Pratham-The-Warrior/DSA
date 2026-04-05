/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

/*
 *You are given a sequence of n
 *integers a1,a2,…,an
 *Your task is to answer q
 *queries:
 *Choose several numbers from a1,a2,…,an such that their bitwise XOR is x
 *If their are multiple solutions, print any of them.
 */

/*
as elemets seems less can we do it like subset sum  DP
to check if target can be formed or not
as n<=500

*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* ===============================================
       THE WINNER TAKES IT ALL, THE LOSER STANDS SMALL
       =============================================== */

    int n;
    cin >> n;

    vector<ull> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        ull x;
        cin >> x;
    }

    return 0;
}