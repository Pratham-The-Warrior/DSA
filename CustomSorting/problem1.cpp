#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    cin >> N;
    int size = 1 << N;

    vector<int> ans(size);
    vector<int> p(size);

    for (int i = 0; i < size; i++)
    {
        ans[i] = i;
        while (i & (1 << p[i]))
            p[i]++;
    }

    stable_sort(ans.begin(), ans.end(), [&](int l, int r)
                { return p[l] > p[r]; });

    for (int i = 0; i < size; i++)
        cout << ans[i] << " ";

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
