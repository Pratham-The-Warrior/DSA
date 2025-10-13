#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T))
        return 0;
    for (int tc = 1; tc <= T; ++tc)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        // Partition into blocks where each block of length k contains exactly numbers 1..k
        vector<int> starts;  // start indices (0-based) of each block
        vector<int> lengths; // lengths k_j
        vector<int> pos1;    // position of 1 inside the block (1-based)
        vector<char> seen(N + 1, 0);
        vector<int> seen_list;
        int cur_max = 0, uniq = 0;
        int block_start = 0;
        for (int i = 0; i < N; ++i)
        {
            int v = A[i];
            if (!seen[v])
            {
                seen[v] = 1;
                seen_list.push_back(v);
                ++uniq;
            }
            if (v > cur_max)
                cur_max = v;
            if (uniq == cur_max)
            {
                int k = cur_max;
                starts.push_back(block_start);
                lengths.push_back(k);
                // find position of 1 in this block
                int p = -1;
                for (int j = block_start; j <= i; ++j)
                    if (A[j] == 1)
                    {
                        p = j - block_start + 1;
                        break;
                    }
                pos1.push_back(p);
                // reset seen
                for (int x : seen_list)
                    seen[x] = 0;
                seen_list.clear();
                // reset for next block
                cur_max = 0;
                uniq = 0;
                block_start = i + 1;
            }
        }

        int m = (int)lengths.size();
        // compute s_j = required left rotations for block j
        vector<int> s(m);
        for (int j = 0; j < m; ++j)
        {
            int k = lengths[j];
            int p = pos1[j]; // 1-based pos of value 1 in block
            // s = (k - p + 1) % k
            int sj = (k - p + 1) % k;
            s[j] = sj;
        }

        // compute x_j from last to first
        vector<int> x(m, 0);
        long long cumulative = 0; // sum of x_{t} for t>j when at j
        for (int j = m - 1; j >= 0; --j)
        {
            int k = lengths[j];
            // x_j ≡ s_j - cumulative  (mod k), pick representative in [0,k-1]
            long long need = s[j] - (cumulative % k);
            int xj = (int)((need % k + k) % k);
            x[j] = xj;
            cumulative += xj;
        }

        // Build operations
        vector<pair<int, int>> ops; // (type, arg) type 1 with arg=k, type 2 with arg=0
        for (int j = 0; j < m; ++j)
        {
            ops.emplace_back(1, lengths[j]);
            for (int t = 0; t < x[j]; ++t)
                ops.emplace_back(2, 0);
        }

        // Output
        cout << "Case #" << tc << ": " << ops.size() << "\n";
        for (auto &op : ops)
        {
            if (op.first == 1)
                cout << "1 " << op.second << "\n";
            else
                cout << "2\n";
        }
    }
    return 0;
}
