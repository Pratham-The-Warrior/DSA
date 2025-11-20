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
    int tt;
    cin >> tt;
    for (long long tc = 1; tc <= tt; ++tc)
    {
        long long N, M;
        cin >> N >> M;
        bool ok = false;

        if (N >= M && N <= 2LL * M - 2)
            ok = true;

        if (!ok && N >= 2LL * M && (N % 2 == 0))
            ok = true;

        cout << "Case #" << tc << ": " << (ok ? "YES" : "NO");
        cout << endl;
    }
    return 0;
}
