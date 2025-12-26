/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
// #include <bits/stdc++.h>
// using namespace std;

/*

Pattern Emerges

Let m = floor(n/2)

n even = 2m
moves: h = m, v = m
Reachable set = full square: |x| ≤ m, |y| ≤ m
Number of points = (2m+1)² = (m+1)² after shifting geometry symmetry
But actual reachable count reduces to:
= (m+1)²

n odd = 2m+1
One direction gets m+1 moves
Shape stretches into a diamond
Count = (m+1)(m+2)*2

Rewrite m = (n−1)/2 → simplifying yields:
= ((n+1)(n+3))/2

*/

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     long long int n;
//     cin >> n;

//     if (n % 2 == 0)
//     {
//         cout << (n / 2 + 1) * (n / 2 + 1) << endl;
//     }
//     else
//     {
//         cout << (n + 1) * (n + 3) / 2 << endl;
//     }

//     return 0;
// }

/*******************************************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct State
{
    int x, y, d;
    bool operator==(State const &other) const
    {
        return x == other.x && y == other.y && d == other.d;
    }
};

struct StateHash
{
    size_t operator()(State const &s) const
    {
        return ((size_t)s.x * 1315423911u) ^ ((size_t)s.y << 16) ^ (size_t)s.d;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Directions: N,E,S,W mapped to dx,dy
    vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    if (n == 0)
    {
        cout << 1 << "\n";
        return 0;
    }

    vector<unordered_set<State, StateHash>> S(n + 1);

    // Step 1: choose any direction
    for (int d = 0; d < 4; d++)
    {
        int dx = moves[d].first, dy = moves[d].second;
        S[1].insert({dx, dy, d});
    }

    // Fill DP
    for (int i = 1; i < n; i++)
    {
        for (auto &st : S[i])
        {
            int x = st.x, y = st.y, d = st.d;
            // Turn left
            int nd = (d + 3) % 4;
            S[i + 1].insert({x + moves[nd].first, y + moves[nd].second, nd});
            // Turn right
            nd = (d + 1) % 4;
            S[i + 1].insert({x + moves[nd].first, y + moves[nd].second, nd});
        }
    }

    // Collect distinct final (x, y)
    unordered_set<long long> uniquePos;
    for (auto &st : S[n])
    {
        long long key = ((long long)st.x << 32) ^ (unsigned long long)(st.y & 0xffffffff);
        uniquePos.insert(key);
    }

    cout << uniquePos.size() << "\n";
    return 0;
}
