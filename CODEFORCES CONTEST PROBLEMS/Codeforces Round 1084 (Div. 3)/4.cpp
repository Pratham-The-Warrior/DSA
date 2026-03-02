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
    ande ke ek aage se leke second ande ke agge tak ke hi elemnts ki
    position badal sakti hai
    so basically i can divide the array into 3 parts
    first -> start to positon x-1
    second -> x to y
    thirst -> y to end
    */

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> p(n);

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        vector<int> B;
        if (x < y)
        {
            B = vector<int>(p.begin() + x, p.begin() + y);

            // rotate B so minimum element comes first
            int idx = min_element(B.begin(), B.end()) - B.begin();
            rotate(B.begin(), B.begin() + idx, B.end());
        }

        vector<int> S;
        for (int i = 0; i < x; i++)
            S.push_back(p[i]);
        for (int i = y; i < n; i++)
            S.push_back(p[i]);

        int pos = 0;
        while (pos < S.size() && S[pos] < B[0])
            pos++;

        for (int i = 0; i < pos; i++)
            cout << S[i] << " ";

        for (auto val : B)
            cout << val << " ";

        for (int i = pos; i < S.size(); i++)
            cout << S[i] << " ";

        cout << endl;
    }

    return 0;
}