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

    int g, c, l;
    cin >> g >> c >> l;

    int maxi = max({g, c, l});
    int mini = min({g, c, l});

    if (maxi - mini >= 10)
        cout << "check again" << endl;
    else
        cout << "final" << " " << g + c + l - mini - maxi << endl;
    return 0;
}