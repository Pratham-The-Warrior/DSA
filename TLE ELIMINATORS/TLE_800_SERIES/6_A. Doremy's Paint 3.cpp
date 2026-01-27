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
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }

        if (mp.size() == 1)
        {
            cout << "Yes" << endl;
            continue;
        }

        if (mp.size() > 2)
        {
            cout << "No" << endl;
            continue;
        }

        vector<int> num;

        for (auto x : mp)
        {
            num.push_back(x.second);
        }

        int diff = abs(num[0] - num[1]);

        if (diff <= 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}