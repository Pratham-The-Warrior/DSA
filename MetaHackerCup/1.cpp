#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        bool possible = true;
        for (int i = 0; i < N; i++)
        {
            if (A[i] > B[i])
            {
                possible = false;
                break;
            }
        }

        if (!possible)
        {
            cout << "Case #" << tc << ": -1\n";
            continue;
        }

        unordered_map<int, vector<int>> source;
        for (int i = 0; i < N; i++)
        {
            source[A[i]].push_back(i);
        }

        unordered_map<int, vector<int>> target;
        for (int i = 0; i < N; i++)
        {
            if (A[i] != B[i])
                target[B[i]].push_back(i);
        }

        vector<int> vals;
        for (int x : B)
            vals.push_back(x);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<pair<int, int>> ops;

        for (int val : vals)
        {
            if (target.find(val) == target.end())
                continue;
            if (source[val].empty())
            {
                possible = false;
                break;
            }

            int src = source[val].back();
            for (int idx : target[val])
            {
                ops.push_back({idx + 1, src + 1});
                A[idx] = val;
                source[val].push_back(idx);
            }
        }

        if (!possible)
        {
            cout << "Case #" << tc << ": -1\n";
        }
        else
        {
            cout << "Case #" << tc << ": " << ops.size() << "\n";
            for (auto &p : ops)
            {
                cout << p.second << " " << p.first << "\n";
            }
        }
    }

    return 0;
}
