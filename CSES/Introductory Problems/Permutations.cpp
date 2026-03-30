/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] - a[i - 1] == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    // 3 5 1 4 2
    // 2 4 1 3
    // 2 4 6 1 3 5
    // 2 4 1 3 5

    vector<int> ans;

    // first all even then all odd

    for (int i = 2; i <= n; i += 2)
    {
        ans.push_back(i);
    }

    for (int i = 1; i <= n; i += 2)
    {
        ans.push_back(i);
    }

    if (check(ans))
    {
        for (auto &x : ans)
        {
            cout << x << " ";
        }
    }
    else
    {
        cout << "NO SOLUTION";
    }

    return 0;
}