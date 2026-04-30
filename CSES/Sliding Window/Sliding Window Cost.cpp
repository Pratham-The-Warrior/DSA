#include <bits/stdc++.h>
using namespace std;

const long long LIM = 9e18;
static long long cur[20005], nxt[20005], price[20005], ship[20005];

// Transition step for item i
void updateState(int i, int n, int cost)
{
    for (int j = 0; j <= n; ++j)
        nxt[j] = LIM;
    for (int j = 0; j <= i; ++j)
    {
        if (cur[j] == LIM)
            continue;
        // Option 1: take shipping
        if (j < n)
            nxt[j + 1] = min(nxt[j + 1], cur[j] + ship[i]);
        // Option 2: pay price with extra cost
        nxt[j] = min(nxt[j], cur[j] + (long long)j * cost + price[i]);
    }
    for (int j = 0; j <= n; ++j)
        cur[j] = nxt[j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; ++i)
        cin >> price[i];
    for (int i = 0; i < n; ++i)
        cin >> ship[i];

    for (int i = 0; i <= n; ++i)
        cur[i] = LIM;
    cur[0] = 0;

    for (int i = 0; i < n; ++i)
        updateState(i, n, c);

    long long ans = LIM;
    for (int i = 0; i <= n; ++i)
        ans = min(ans, cur[i]);
    cout << ans << "\n";
    return 0;
}
