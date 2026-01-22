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

        vector<long long int> s(n), u(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            s[i]--;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> u[i];
        }

        vector<vector<long long int>> groups(n);

        for (int i = 0; i < n; i++)
        {
            groups[s[i]].push_back(u[i]);
        }

        vector<long long> ans(n);

        for (int i = 0; i < n; i++)
        {
            sort(groups[i].begin(), groups[i].end(), greater<int>());
        }

        vector<vector<long long>> prefix(n);

        for (int i = 0; i < n; i++)
        {
            prefix[i].push_back(0);
            for (auto val : groups[i])
            {
                prefix[i].push_back(val + prefix[i].back());
            }
        }

        for (int i = 0; i < n; i++)
        {
            long long int sz = groups[i].size();
            long long int total_sum = prefix[i][sz];

            for (int k = 1; k <= sz; k++)
            {
                if (sz % k == 0)
                {
                    ans[k - 1] += total_sum;
                }
                else
                {
                    long long int max_take = (sz / k) * k;
                    ans[k - 1] += prefix[i][max_take];
                }
            }
        }

        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}