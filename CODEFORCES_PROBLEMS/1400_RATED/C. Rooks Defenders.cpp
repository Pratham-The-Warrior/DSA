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

    /* ====================================

      here logic seems simple but time complexity is the big problem as  we will have to find a way to
      answer each query in O(1) or atmax O(logn) time
      to ensure the each block in a subrectangle is attacked by a rook we would need to ensure that if there is at least
      one rook either in its row or in its column then only we can say that the position will be attacked by the rook



      A Fenwick Tree (BIT) is a data structure that supports:
        Point update
        Prefix sum query
        in O(log n) time.
     ====================================*/

    int t;
    cin >> t;
    while (t--)
    {
    }

    return 0;
}