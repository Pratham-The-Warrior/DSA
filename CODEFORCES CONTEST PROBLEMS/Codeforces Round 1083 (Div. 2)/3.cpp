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

        vector<vector<int>> a(n);

        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            vector<int> temp(k);
            for (int j = 0; j < k; j++)
            {
                cin >> temp[j];
            }
            reverse(temp.begin(), temp.end());
            unordered_set<int> seen; // positions need to be maintained
            for (auto x : temp)
            {
                if (!seen.count(x))
                {
                    a[i].push_back(x);
                    seen.insert(x);
                }
            }
        }

        vector<int> ans;
        unordered_set<int> used;

        while (!a.empty())
        {

            for (auto &x : a)
            {
                vector<int> temp;
                for (auto &y : x)
                {
                    if (!used.count(y))
                    {
                        temp.push_back(y);
                    }
                }
                x = temp;
            }

            sort(a.begin(), a.end());

            for (auto x : a.front())
            {
                ans.push_back(x);
                used.insert(x);
            }

            a.erase(a.begin());
        }

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}