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
    /*
    As all have same speed relatively all are at rest with each other
    so greeting can happen only if one of them stops
    condition is a[i]<b[i]<b[j]<a[j]
    in this conditon greeting can happen

    */
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<long long, long long>> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first >> v[i].second;
        }

        /*BRUTE FORCE*/
    }

    return 0;
}